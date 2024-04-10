#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;

int T;
int n;
int cnt[2];
int a[100005];

ll check(int begin) {
    ll sum = 0;
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        while (a[j] != begin) ++j;
        sum += abs(j - i);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T--) {
        cin >> n;
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] &= 1;
            ++cnt[a[i]];
        }
        if (abs(cnt[0] - cnt[1]) > 1) {
            cout << "-1\n";
            continue;
        }
        if (cnt[0] == cnt[1]) {
            cout << min(check(0), check(1)) << "\n";
        } else if (cnt[0] > cnt[1]) {
            cout << check(0) << "\n";
        } else {
            cout << check(1) << "\n";
        }
    }
    return 0;
}