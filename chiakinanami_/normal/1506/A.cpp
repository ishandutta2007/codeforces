#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
ll n, m, x;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld", &n, &m, &x);
        x--;
        ll r = x % n;
        ll c = x / n;
        printf("%lld\n", r * m + c + 1);
    }
}