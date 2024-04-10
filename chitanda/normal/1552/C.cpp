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

const int maxn = 205;
int T;
int n, k;
int x[maxn], y[maxn];
int tag[maxn];

int check(int i, int j) {
    if (x[j] < x[i]) swap(i, j);
    return x[j] < y[i] && !(y[j] > x[i] && y[j] < y[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    while (T--) {
        cin >> n >> k;
        fill(tag, tag + 2 * n, 0);
        for (int i = 0; i < k; ++i) {
            cin >> x[i] >> y[i];
            --x[i], --y[i];
            if (x[i] > y[i]) swap(x[i], y[i]);
            tag[x[i]] = tag[y[i]] = 1;
        }
        vector<int> re;
        for (int i = 0; i < 2 * n; ++i) {
            if (!tag[i]) re.pb(i);
        }
        for (int i = 0; i < n - k; ++i) {
            x[k + i] = re[i];
            y[k + i] = re[n - k + i];
            // cout << "link: " << x[k + i] << " " << y[k + i] << "\n";
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                cnt += check(i, j);
            }
        cout << cnt << "\n";
    }
    return 0;
}