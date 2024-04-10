#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli precalc[MAXN];
lli mod=998244353;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    precalc[0]=1;
    for(int i=1;i<=n;i++){
        precalc[i]=precalc[i-1]*(lli)10%mod;
    }
    for(int i=1;i<=n;i++){
        int spc=n-i;
        lli ans=0;
        if(spc==0)ans=1;
        if(spc>0)ans=(ans+(precalc[spc-1]*(lli)18%mod))%mod;
        if(spc>=2)ans=(ans+((precalc[spc-2]*(lli)81%mod)*(lli)(spc-2+1)%mod))%mod;
        printf("%lli ",ans*(lli)10%mod);
    }
    return 0;
}