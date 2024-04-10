#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, p1, p2, k;
inline ll gcd(ll a, ll b) {
    if (b == 0) return a; else return gcd(b, a % b);
}
int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld%lld", &p1, &p2, &k);
        if (k == 1) {
            puts("REBEL");
            continue;
        }
        ll g = gcd(p1, p2);
        p1 /= g, p2 /= g;
        if (p1 > p2) swap(p1, p2);
        if (p2 == 1) puts("OBEY"); else  
        puts((p2 - 1 + p1 - 1) / p1 < k ? "OBEY" : "REBEL");
    }
}