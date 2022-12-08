#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n, k;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &n, &k);
        for(int i=1; i<=k-3; i++) printf("1 ");
        n -= k-3;
        k = 3;

        if(n%2){
            printf("%lld %lld 1\n", n/2, n/2);
        }
        else{
            ll tx = (n-2)/2, ty = 2;
            while(tx * ty / __gcd(tx, ty) > n/2){
                ty *= 2;
                tx = (n-ty)/2;
            }
            printf("%lld %lld %lld\n", tx, tx, ty);
        }
    }
}