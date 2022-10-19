#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
void solve(){
    scanf("%d %d %d",&a,&b,&c);
    printf("%lld %d %d\n",b*(long long)1e9+a,b,c);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}