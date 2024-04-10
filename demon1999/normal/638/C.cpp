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

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, a, b, bd[2 * ma];
vector<int> qq[300000];
vector<pair<int, int> > edge[2 * ma];

void dfs(int nu, int pr) {
    int k = 0;
    if (k == bd[nu]) k++;
    for (auto v : edge[nu]) {
        if (v.fi != pr) {
            qq[k].push_back(v.se);
            bd[v.fi] = k;
            k++;
            if (k == bd[nu]) k++;
        }
    }
    for (auto v : edge[nu]) {
        if (v.fi != pr) {
            dfs(v.fi, nu);
        }
    }
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("qqq.in", "r",  stdin);
    cin >> n;
    forn (i, n) bd[i] = -1;
    forn (i, n - 1) {
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(mp(b, i + 1));
        edge[b].push_back(mp(a, i + 1));
    }
    dfs(0, -1);
    int i = 0;
    while (sz(qq[i])) i++;
    cout << i << "\n";
    forn(j, i) {
        cout << sz(qq[j]) << " ";
        for (int v : qq[j]) cout << v << " ";
        cout << endl;
    }
    return 0;
}