#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 201010
int n;
string s;
int a[maxn], sum[maxn];

int get(int l, int r) { return sum[r] - sum[l]; }
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    rep(i, n) a[i] = s[i] == '(' ? 1 : -1;

    sum[0] = 0;
    rep(i, n) sum[i + 1] = a[i] + sum[i];

    if (sum[n] != 0) {
        cout << "No";
        return 0;
    }

    int first_neg = n, last_pos = -1;
    rep(i, n) if (get(0, i) < 0) {
        first_neg = i;
        break;
    }

    for (int i = n; i--; ) {
        if (get(i, n) > 0) {
            last_pos = i;
            break;
        }
    }
    if (first_neg == n) {
        cout << "Yes";
        return 0;
    }
    clog << first_neg << ' ' << last_pos << endl;

    for (int i = last_pos; i >= first_neg; --i) {
        swap(a[i], a[i - 1]);
    }

    int t = 0;
    rep(i, n) {
        t += a[i];
        if (t < 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}