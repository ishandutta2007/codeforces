#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int m,mem[1005][1005],vis[1005][1005];

int f(int n,int k){
    if(vis[n][k]==m)return mem[n][k];
    vis[n][k]=m;
    int &res=mem[n][k];
    if(n==0||k==1)return res=1;
    return res=(f(m-n,k-1)+f(n-1,k))%mod;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        m=n;
        cout<<f(n,k)<<'\n';
    }

    return 0;
}