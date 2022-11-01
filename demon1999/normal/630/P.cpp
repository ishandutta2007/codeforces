#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
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
typedef double ld;
using namespace std;

struct T { int x, y; };
T t = {1, 2};
ld pi = acos(-1);
const int ma = 2 * 131072;

double n, r, ans, a, b, c;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    cin >> n >> r;
    a = pi / n;
    b = pi / (2. * n);
    cout.precision(30);
    //cout << pi << endl;
    cout << n * r * r * sin(a) * sin(b) / (sin(pi - a - b)) << endl;
    return 0;
}