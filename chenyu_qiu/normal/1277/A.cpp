#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void work()
{
    ll n;
    scanf("%lld",&n);
    int ans=0;
    for(int i=1;i<=9;i++){
        ll k=i;
        while(k<=n){
            //printf("%lld\n",k);
            ans++;
            k=k*10+i;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    //T=1;
    while(T--){
        work();
    }
}