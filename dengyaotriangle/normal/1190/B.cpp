#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];
int g[maxn];
int g1[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    long long sm=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    g[0]=-1;
    for(int i=1;i<=n;i++){
        g[i]=g[i-1]+1;
        sm+=a[i];
    }
    long long ocn=0;
    int sc=0;
    for(int i=1;i<=n;i++){
        ocn+=a[i]-g[i];
    }
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) sc++;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=0&&a[i]!=a[i-1]){
            long long cnt=ocn;
            int nsc=sc;
            if(a[i]==a[i+1]&&i!=n) nsc--;
            if(a[i]-1==a[i-1]&&i!=1) nsc++; 
            cnt--;
            if(nsc){
                continue;
            }
            if(cnt%2==0){
                cout<<"sjfnb";
                return 0;
            }
        }
    }
    cout<<"cslnb";
    return 0;
}