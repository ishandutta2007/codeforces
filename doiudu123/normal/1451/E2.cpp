#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1004, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    /*
     a ^ b = a | b - a & b
     a + b = a | b + a & b;
     2 * a | b - a ^ b = a + b
     a + b = a ^ b + (a & b) * 2
     */
    int n;
    cin >> n;
    vector <int> xorr(n, 0);
    vector <int> cnt(n, 0);
    cnt[0]++;
    fop (i,1,n) {
        cout << "XOR 1" << ' ' << i + 1 << endl;
        cin >> xorr[i];
        cnt[xorr[i]]++;
    }
    vector <int> ans(n);
    fop (i,0,n) {
        if (cnt[i] >= 2) {
            vector <int> p;
            fop (j,0,n) {
                if (xorr[j] == i) {
                    p.pb(j);
                    if (p.size() == 2) break;
                }
            }
            cout << "OR " << p[0] + 1 << ' ' << p[1] + 1 << endl;
            cin >> ans[p[0]];
            fop (i,0,n) if (i != p[0]) ans[i] = ans[p[0]] ^ xorr[p[0]] ^ xorr[i];
            cout << "! ";
            for (int i : ans) cout << i << ' ';
            cout << endl;
            return 0;
        }
    }
    int p, q, x, sum = 0;
    fop (i,0,n) {
        if (xorr[i] == n - 1) {
            q = i;
            break;
        }
    }
    if (q == 1) p = 2;
    else p = 1;
    cout << "AND " << p + 1 << ' ' << 1 << endl;
    cin >> x;
    sum += x;
    cout << "AND " << p + 1 << ' ' << q + 1 << endl;
    cin >> x;
    sum += x;
    ans[p] = sum;
    fop (i,0,n) if (i != p) ans[i] = ans[p] ^ xorr[p] ^ xorr[i];
    cout << "! ";
    for (int i : ans) cout << i << ' ';
    cout << endl;
    return 0;
    // 0 3 2 1
}