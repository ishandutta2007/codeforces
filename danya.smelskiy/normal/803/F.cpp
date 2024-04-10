#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;


int n,x;
long long ans[100005];
int kol[100005];

inline long long p(long long x,long long y){
    long long res=1;
    while (y){
        if (y&1) res=(res*x)%md;
        x=(x*x)%md;
        y>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        ++kol[x];
    }
    for (int i=1e5;i>0;--i){
        int k=0;
        for (int j=1;j*i<=1e5;++j)
            k+=kol[j*i];
        ans[i]=p(2,k)-1;
        for (int j=i+i;j<=1e5;j+=i){
            ans[i]-=ans[j];
            if (ans[i]<0) ans[i]+=md;
        }
    }
    cout<<ans[1];
}