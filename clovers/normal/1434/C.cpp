#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;

ll a,b,c,d;
void solve(){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    if(a>b*c){
        puts("-1");
        return;
    }
    if(a<=d*b){
        printf("%lld\n",a);
    }
    else{
        ll k=a/(d*b)+1;
        ll ret=a*k-d*b*k*(k-1)/2;
        printf("%lld\n",ret);
    }
}

int main(){
    int T=1; scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}