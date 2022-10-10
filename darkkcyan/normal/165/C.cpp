#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int k;
vi a;
void read() {
    scanf("%d", &k);
    char s[1010101];
    scanf("%s", s);
    a.push_back(0);
    for (char* i = s; *i; ++i) a.push_back(*i - '0' + a.back());
}

long process() {
    long ans = 0;
    for (int i = 1; i < sz(a); ++i) {
        long t = a[i] - k;
        ans += upper_bound(a.begin(), a.begin() + i, t) - lower_bound(a.begin(), a.begin() + i, t);
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    cout << process();

    return 0;
}