#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn],b[maxn<<3];
int c[maxn<<3];

bool ah[maxn];
int cl=1;

int chk(int k){
    for(int i=1;i<=n;i++) ah[i]=0;

    for(int i=1;i<=n;i++) ah[a[i]]=1;
    for(int i=1;i<=n;i++) c[i]=b[i];
    int cl=1;
    for(int i=1;i<=k;i++){
        c[cl+n]=0;
        ah[c[cl]]=1;
        cl++;
    }
    int cur=0;
    for(int i=cl;i<=n+cl-1;i++){
        if(c[i]==1){
            bool ok=1;
            for(int j=i;j<n+cl-1;j++){
                if(c[j]!=c[j+1]-1)ok=0;
            }
            if(ok)cur=c[n+cl-1];
        }
    }
    if(k!=0) cur=0;
    int ans=0;
    while(cur!=n){
        if(!ah[cur+1])return -1;
        ah[cur+1]=0;
        ah[c[cl]]=1;
        cl++;
        cur++;
        ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int cur=0;
    for(int i=1;i<=n;i++){
        if(b[i]==1){
            bool ok=0;
            for(int j=i+1;j<=n;j++){
                if(b[j]!=b[j-1]+1)ok=1;
            }
            if(!ok) cur=b[n];
        }
    }
    int l=1,r=n;
    while(r-l>5){
        int m=(l+r)/2;
        if(chk(m)!=-1)r=m;
        else l=m;
    }
    if(chk(0)!=-1){
        cout<<chk(0);
        return 0;
    }
    for(int i=l;i<=r;i++){
        if(chk(i)!=-1){
            cout<<i+chk(i);
            return 0;
        }
    }
    return 0;
}