#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=14;
const int mdn=1000000007;

int n;
int a[maxn];
int p[maxn][maxn];
inline int qpw(int bse,int ex=mdn-2){int ret=1;while(ex){if(ex&1){ret=ret*(long long)bse%mdn;}bse=bse*(long long)bse%mdn;ex>>=1;}return ret;}

int f[1<<maxn];
int rp[maxn][1<<maxn];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        p[i][j]=a[i]*(long long)qpw(a[i]+a[j])%mdn;
    }
    for(int i=0;i<n;i++){
        rp[i][0]=1;
        for(int j=1;j<(1<<n);j++){
            int u=31-__builtin_clz(j&-j);
            rp[i][j]=rp[i][j-(1<<u)]*(long long)p[i][u]%mdn;
        }
    }
    for(int i=1;i<(1<<n);i++){
        if(__builtin_popcount(i)==1){
            f[i]=1;
        }else{
            for(int j=i;j;j=(j-1)&i){
                int prod=1;
                for(int k=0;k<n;k++)if((j>>k)&1)prod=prod*(long long)rp[k][i-j]%mdn;
                f[i]=(f[i]+f[j]*(long long)prod)%mdn;
            }
            f[i]=(mdn+1-f[i])%mdn;
        }
    }
    int ans=0;
    for(int i=1;i<(1<<n);i++){
        int prod=1;
        for(int k=0;k<n;k++)if((i>>k)&1)prod=prod*(long long)rp[k][(1<<n)-1-i]%mdn;
        ans=(ans+__builtin_popcount(i)*(long long)f[i]%mdn*prod)%mdn;
    }
    cout<<ans;
    return 0;
}