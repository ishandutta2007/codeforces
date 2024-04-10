#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>
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
typedef long double ld;
using namespace std;

struct T { double x, m, v; int nu;};
int n, m, k1, k2, st, fi, use[1000];
vector<int> a[500], pp;
char ans[500];
void dfs(int nu) {
    ans[nu] = 'c';
    use[nu] = 1;
    k1++;
    for (auto v : a[nu]) {
        if (use[v] == 0) {
            dfs(v);
        }
        if (use[v] == 2) k2++;
    }
    use[nu] = 2;
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("a.in", "r",  stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> m;
    forn (i, m) {
        cin >> st >> fi;
        st--;
        fi--;
        a[st].push_back(fi);
        a[fi].push_back(st);
    }
    ll q = 0;
    forn (i, n) {
        ans[i] = 'a';
        if (sz(a[i]) == n - 1) {
            ans[i] = 'b';
            use[i] = 1;
            q++;
            for (auto v : a[i])
                if (use[v] == 0) m--;
        }
    }
    forn (i, n) {
        if (use[i] == 0) {
            dfs(i);
            //cout << k1 << " " << k2 << " " << m << " " << q << endl;
            if (k2 != (k1 - 1) * k1 / 2 || m - k2 != (n - k1 - q) * (n - k1 - q - 1) / 2) {
                cout << "No";
                re 0;
            }
            break;
        }
    }
    cout << "Yes\n";
    forn (i, n)
        cout << ans[i];
    return 0;
}