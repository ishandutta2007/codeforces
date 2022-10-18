#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
int a[maxn],h[maxn];
bool g[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        h[a[i]]++;
    }
    int mi=-1,mx=0;
    for(int i=0;i<maxn;i++){
        if(h[i]>mx){
            mx=h[i];
            mi=i;
        }
    }
    int si=0;
    for(int i=1;i<=n;i++){
        if(a[i]==mi){
            g[i]=1;
            si=i;
        }
    }
    cout<<n-mx<<'\n';
    for(int i=si-1;i>=1;i--){
        if(a[i]!=mi){
            int t=1;
            if(a[i]>mi) t=2;
            cout<<t<<' '<<i<<' '<<i+1<<'\n';
            a[i]=mi;
        }
    }
    for(int i=si+1;i<=n;i++){
        if(a[i]!=mi){
            int t=1;
            if(a[i]>mi) t=2;
            cout<<t<<' '<<i<<' '<<i-1<<'\n';
            a[i]=mi;
        }
    }
    return 0;
}