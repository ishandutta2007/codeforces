#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
int main(){
    scanf("%lld%lld",&n,&m);
    if(n>m) swap(n,m);
    if(n==1){
        ll ans=m-m%6;
        if(m%6>=4) ans+=(m%6-3)*2;
        printf("%lld\n",ans);
        return 0;
    }
    if(n==2){
        if(m<=2){
            puts("0");
            return 0;
        }
        else{
            if(m==3) puts("4");
            else if(m==7) puts("12");
            else printf("%lld\n",m*n);
        }
        return 0;
    }
    printf("%lld\n",(n*m)-(n*m%2));
    return 0;
}