#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll num(char c) {
    return 1 << (c - 'a');
}

ll n, T;
char S[100005];
int main() {
    scanf("%lld%lld%s", &n, &T, S + 1);
    T -= num(S[n]) - num(S[n - 1]);
    vector<ll> V;
    for (int i = 1; i <= n - 2; i++) {
        V.push_back(num(S[i]));
        T += num(S[i]);
    }
    if (T < 0 || T % 2) return !printf("No\n");
    T /= 2;
    sort(V.rbegin(), V.rend());
    for (ll i : V) {
        if (i <= T) T -= i;
    }
    if (T) printf("No\n");
    else printf("Yes\n");
}