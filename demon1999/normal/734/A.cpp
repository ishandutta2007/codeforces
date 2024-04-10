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

int n, k1, k2;
string s;
 
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> s;
    forn (i, n) {
        if (s[i] == 'A') k1++;
        else
            k2++;
    }
    if (k1 < k2)
        cout << "Danik";
    else
        if (k1 > k2)
            cout  << "Anton";
        else
            cout << "Friendship";
    return 0;
}