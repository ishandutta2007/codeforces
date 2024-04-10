#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
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

const ll mod = 998244353;
int n, m, xl, yl, use[200][200];
string s[100000];
vector<int> a;

void dfs(int x, int y) {
    use[x][y] = 1;
    if (x && s[x - 1][y] == '*' && !use[x - 1][y]) {
        cout << "U";
        dfs(x - 1, y);
        re;
    }
    if (y && s[x][y - 1] == '*' && !use[x][y - 1]) {
        cout << "L";
        dfs(x, y - 1);
        re;
    }
    if (x + 1 < n && s[x + 1][y] == '*' && !use[x + 1][y]) {
        cout << "D";
        dfs(x + 1, y);
        re;
    }
    if (y + 1 < m && s[x][y + 1] == '*' && !use[x][y + 1]) {
        cout << "R";
        dfs(x, y + 1);
        re;
    }
    if (xl == x - 1) {
        cout << "U";
    }
    if (yl == y - 1)
        cout << "L";
    if (xl == x + 1)
        cout << "D";
    if (yl == y + 1)
        cout << "R";
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("bridge.in", "r",  stdin);
    //freopen("bridge.out", "w", stdout);
    cin >> n >> m;
    forn (i, n) {
        cin >> s[i];
        forn (j, m)
            if (s[i][j] == 'S') {
                xl = i;
                yl = j;
            }
    }
    dfs(xl, yl);
    return 0;
}