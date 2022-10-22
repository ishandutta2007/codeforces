#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
char s[MN];
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n); vector<int> can(n); vector<int> psa;
    for (auto &au : a) scanf ("%d",&au);
    scanf ("%s",s);
    for (int i = 0; i < n; i++) psa.push_back((psa.empty()?0:psa.back()) + s[i] - '0');
    for (int i = 0; i < n; i++) if (a[i] - 1 > i) {
        int togo = a[i] - 1;
        if (psa[togo-1] - (i?psa[i-1]:0) != togo - i) return !printf ("NO\n");
    }
    printf ("YES\n");
    return 0;
}