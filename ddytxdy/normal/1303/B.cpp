#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,g,b;
void solve(){
    scanf("%lld%lld%lld",&n,&g,&b);
    int num=n/(g+b),re=n-(g+b)*num;int m=n+1>>1;
    int p=num*g+min(re,g),q=num*b+max(0ll,re-g);
    if(p>=q)printf("%lld\n",n);
    else if(m%g==0)printf("%lld\n",(m/g-1)*(g+b)+g);
    else printf("%lld\n",m/g*(b+g)+m%g);
}
signed main(){
    scanf("%lld",&T);
    while(T--)solve();
    return 0;
}