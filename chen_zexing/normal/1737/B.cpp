#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
long long cal(long long x){
    if(!x) return 0;
    long long temp=sqrt(x);
    while(temp*temp>x) temp--;
    while((temp+1)*(temp+1)<=x) temp++;
    long long bonus=(x-temp*temp)/temp+1;
    return (temp-1)*3+bonus;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",cal(r)-cal(l-1));
    }
    return 0;
}