#include <cstdio>
#include <cstring>
#include <cmath>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

#define LOCAL

#ifdef LOCAL
#include <iostream>
#else
#include <iostream>
#endif

const int max_a = 1e6 + 100;

int n, k;
int s[max_a];
int mn;

int sum(int l, int r) {
    int result = s[r];
    if (l) result -= s[l - 1];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin >> n >> k;
    mn = max_a;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++s[a];
        mn = min(mn, a);
    }
    for (int i = 1; i < max_a; ++i)
        s[i] += s[i - 1];
    int ans = min(k + 1, mn);
    for (int d = k + 2; d <= mn; ++d) {
        int l = d, sm = 0;
        while (l < max_a) {
            sm += sum(l, min(l + k, max_a - 1));
            l += d;
        }
        if (sm == n)
            ans = d;
    }
    cout << ans << endl;
    return 0;
}