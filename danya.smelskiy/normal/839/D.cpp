#include <bits/stdc++.h>
using namespace std;


const long long md=1e9+7;
long long kol[1000005];
long long kol2[1000005];
long long ans[1000005];
long long res,n,x;

inline long long p(long long x,long long y){
    long long res=1;
    while (y) {
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        ++kol[x];
    }
    for (int i=1e6;i>1;--i) {
        for (int j=i;j<=1e6;j+=i)
            kol2[i]+=kol[j];
        if (!kol2[i]) continue;
        ans[i]=(kol2[i]*p(2,kol2[i]-1))%md;
        for (int j=i+i;j<=1e6;j+=i){
            ans[i]-=ans[j];
            if (ans[i]<0) ans[i]+=md;
        }
        res=(res+(ans[i]*i)%md)%md;
    }
    cout<<res;
}