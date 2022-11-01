#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
#define point pair <int, int>
#define re return
#define se second
#define fi first
#define mp(a, b) make_pair(a, b)
#define mp1(a, b, c, d) make_pair(mp(a, b), mp(c, d))
using namespace std;
typedef long long ll;
const ll mod = (1e9) + 7;

int n, a, b;
string s;
int main() {
    iostream::sync_with_stdio(0);
    //freopen("a.in", "r", stdin);
    cin >> n >> a >> b >> s;
    cout << abs(s[a - 1] - s[b - 1]);
}