#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
    int n;
    cin >> n;
    vi a(1 << (n + 1));
    vi s(1 << (n + 1));
    for (int i = 2; i < (1 << (n + 1)); ++i) cin >> a[i];

    long long res = 0;
    for (int i = (1<<n) - 1; i >= 1; --i) {
        s[i] = max(a[i * 2] + s[i * 2], a[i * 2 + 1] + s[i * 2 + 1]);

        res += max(a[i * 2] + s[i * 2], a[i * 2 + 1] + s[i * 2 + 1]) -
               min(a[i * 2] + s[i * 2], a[i * 2 + 1] + s[i * 2 + 1]);
    }

    cout << res << endl; 

    return false;
}

int main() {

    while (solve());
    
    return 0;
}