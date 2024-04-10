#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <bitset>
//#include "horses.h"
#define sz(a) (int)a.size()
#define re return
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

typedef long double ld;
const ll ma = 131072 * 4, mod = 1000000007;
const ld eps = 1e-10;
ll n, m, k, ans[100000];
vector<pair<int, int> > b, f;
map<int, vector<int> > qq;
bool ok = false;
int main() {
    iostream::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    f.resize(n);
    b.resize(m);
    forn (i, n) {
        cin >> f[i].fi;
        qq[f[i].fi].push_back(i + 1);
    }
    forn (i, m) {
        cin >> b[i].fi;
        if (sz(qq[b[i].fi]) == 0) {
            cout << "Impossible"; re 0;
        }
    }
    forn (i, m) {
        if (sz(qq[b[i].fi]) > 1) {
            cout << "Ambiguity"; re 0;
        }
    }
    cout << "Possible\n";
    forn (i, m) {
        cout << qq[b[i].fi][0] << " ";
    }
    re 0;
}