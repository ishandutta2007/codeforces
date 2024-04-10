#include <bits/stdc++.h>
   
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
   
using namespace std;
   
typedef long long ll;
typedef pair<int, int> pii;

int n, k1, k2, k3, k4;
string s;
 
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> k1 >> k2 >> k3 >> k4;
    int kp = min(k1, min(k3, k4));
    cout << kp * 256 + min(k1 - kp, k2) * 32;
    return 0;
}