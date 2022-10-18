#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=21;
const int mdn=31607;

int qpw(int bse,int ex=mdn-2){
    int ret=1;
    for(;ex;ex>>=1,bse=bse*bse%mdn)if(ex&1)ret=ret*bse%mdn;
    return ret;
}

const int inv1e4=qpw(10000);

int n;
int p[maxn][maxn];
int f[1<<maxn];//f[S] : prob that all g\in S is 1
int g[1<<maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int x;cin>>x;
        p[i][j]=x*inv1e4%mdn;
    }
    int ans=0;
    for(int t=0;t<4;t++){
        for(int i=0;i<(1<<n);i++)f[i]=1;
        int wt=1;
        for(int i=0;i<n;i++){
            int msk=0;
            if(t&1)msk|=1<<i;
            if(t>>1)msk|=1<<(n-i-1);
            g[0]=1;
            int tt=1;
            for(int j=0;j<n;j++){
                if(msk&(1<<j)){
                    wt=wt*p[i][j]%mdn;
                    g[1<<j]=1;
                }else g[1<<j]=p[i][j];
                tt=tt*g[1<<j]%mdn;
            }
            for(int j=1;j<(1<<n);j++){
                int k=j&-j;
                if(j!=k)g[j]=g[j-k]*(long long)g[k]%mdn;
            }
            for(int j=0;j<(1<<n);j++)f[j]=f[j]*(g[j]+mdn-tt)%mdn;
        }
        for(int i=0;i<(1<<n);i++){
            if(__builtin_parity(i)^(t&1)^(t>>1))ans=(ans+(mdn-wt)*f[i])%mdn;
            else ans=(ans+wt*f[i])%mdn;
        }
    }
    cout<<(mdn-ans+1)%mdn;
    return 0;
}