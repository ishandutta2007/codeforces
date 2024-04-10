#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int max_n = 100011, max_m = 10011, inf = 1000111222;
const ll inff = 1000111222333444;

char c[1000011];
map<int, int> mp;
int a[max_n];

int to_int(char c) {
    return c - 'a';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%s", c);
        int len = strlen(c);
        int val = 0;
        for (int q = 0; q < len; ++q) {
            val ^= 1 << to_int(c[q]);
        }
        a[i] = val;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int add = mp[a[i]];
        for (int q = 0; q < 26; ++q) {
            int val = a[i] ^ (1 << q);
            add += mp[val];
        }
        ans += add;
        ++mp[a[i]];
    }
    cout << ans << endl;
    return 0;
}