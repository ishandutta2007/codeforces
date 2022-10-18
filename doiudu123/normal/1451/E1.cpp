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
     a ^ b, a & b -> a + b = ?
     , b & c -> b + c = ?
     a ^ c, a & c -> a + c = ?
     get a
     a + b = a | b + a & b;
     a + b = a ^ b + (a & b) * 2
     */
    int n;
    cin >> n;
    vector <int> ans(n, 0);
    int and12, and23, and13, xor12, xor13;
    cout << "AND 1 2" << endl;
    cin >> and12;
    cout << "AND 2 3" << endl;
    cin >> and23;
    cout << "AND 3 1" << endl;
    cin >> and13;
    cout << "XOR 1 2" << endl;
    cin >> xor12;
    cout << "XOR 1 3" << endl;
    cin >> xor13;
    int ab = xor12 + and12 * 2, ac = xor13 + and13 * 2, bc = (xor12 ^ xor13) + and23 * 2;
    ans[0] = (ab + bc + ac) / 2 - bc;
    ans[1] = (ab + bc + ac) / 2 - ac;
    ans[2] = (ab + bc + ac) / 2 - ab;
    fop (i,3,n) {
        cout << "XOR 1 " << i + 1 << endl;
        cin >> ans[i];
        ans[i] ^= ans[0];
    }
    cout << "! ";
    for (int i : ans) cout << i << ' ';
    cout << endl;
}