#include <bits/stdc++.h>
using namespace std;
const long long md=998244353;
int a,b,cc;
long long c[5005][5005];
long long f[10005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>cc;
    c[0][0]=1;
    for (int i=1;i<=5000;++i) {
        for (int j=0;j<=5000;++j){
            c[i][j]=c[i-1][j];
            if (j) c[i][j]=(c[i-1][j-1]+c[i][j]);
            if (c[i][j]>=md) c[i][j]-=md;
        }
    }
    f[0]=1;
    for (long long i=1;i<=5000;++i)
        f[i]=(f[i-1]*(i))%md;
    long long ans=1;
    for (int i=1;i<=min(a,b);++i) {
        ans=(ans+((((c[a][i]*c[b][i])%md))%md)*f[i]%md)%md;
    }
    long long res=0;
    long long res1=0;
    for (int i=0;i<=min(cc,a);++i) {
        long long nw=(f[i]*c[a][i])%md;
        nw=(nw*c[cc][i])%md;
        res1=(res1+nw)%md;
    }
    for (int i=0;i<=(min(cc,b));++i) {
        long long nw=(f[i]*c[b][i])%md;
        nw=(nw*c[cc][i])%md;
        nw=(nw*ans)%md;
        res=(res+(nw*res1)%md);
        if (res>md) res-=md;
    }
    cout<<res;
}