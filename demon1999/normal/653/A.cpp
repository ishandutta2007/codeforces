#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
const int ma = 2 * 131072;

unordered_map<int, int> a;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
//    assert(freopen("qqq.in", "r",  stdin));
    int n;
    cin >> n;
    forn (i, n) {
        int q;
        cin >> q;
        a[q] = 1;
        if (a[q - 1] && a[q + 1]) {
                cout << "YES"; re 0;
        }
        if (a[q - 1] && a[q - 2]) {
                cout << "YES"; re 0;
        }
        if (a[q + 2] && a[q + 1]) {
                cout << "YES"; re 0;
        }
    }
    cout << "NO";
    return 0;
}