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
#include <unordered_map>
#define forn(i, n) for(int i = 0; i < int(n); i++)
//#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

const int ma = 100000 * 5 + 1000;
int n, m, a, b, pr[ma], szz[ma];
vector<int> edge[ma], nu1, nu2;
vector<pii> edge1[ma];
string s;
vector<ll> qq, q;
//unordered_map<ll, int> q, qq;
ll mp(ll a, ll b) {
    re a * 1000000 + b;
}

void dfs(int nu, int pr) {
    for (auto v : edge[nu])
        if (v != pr) dfs(v, nu);
    if (pr != -1)
        nu1.push_back(nu),
        nu2.push_back(pr);
}


int get_root(int a) {
    if (pr[a] == a) re a;
    pr[a] = get_root(pr[a]);
    re pr[a];
}

void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    //if (a == b)assert(0);
    if (szz[a] > szz[b]) swap(a, b);
    pr[a] = b;
    szz[b] += szz[a];
    forn (i, sz(edge1[a])) {
        edge1[b].push_back(edge1[a][i]);
    }
    edge1[a].clear();
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    cin >> n;
    forn (i, n - 1) {
        cin >> a >> b;
        a--;
        b--;
        q.push_back(mp(min(a, b), max(a, b)));
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    sort(q.begin(), q.end());
    int ans = n - 1;
    forn (i, n - 1) {
        cin >> a >> b;
        a--;
        b--;
        if (binary_search(q.begin(), q.end(), mp(min(a, b), max(a, b)))) ans--;
        qq.push_back(mp(min(a, b), max(a, b)));
        edge1[a].push_back({b, a});
        edge1[b].push_back({a, b});
    }
    forn (i, n) {pr[i] = i; szz[i] = sz(edge1[i]);}
    sort(qq.begin(), qq.end());
    dfs(0, -1);
    //forn (i, n - 1) cout << nu1[i] << " " << nu2[i] << endl;
    //re 0;
    cout << ans << "\n";
    forn (i, n - 1) {
        a = nu1[i];
        b = nu2[i];
        if (binary_search(qq.begin(), qq.end(), mp(min(a, b), max(a, b)))) {
            unite(a, b);
        }
        else {
            cout << a + 1 << " " << b + 1 << " ";
            a = get_root(a);
            while (get_root(edge1[a][sz(edge1[a]) - 1].fi) == a) {
                edge1[a].pop_back();
                szz[a]--;
            }
            cout << edge1[a][sz(edge1[a]) - 1].fi + 1 << " " << edge1[a][sz(edge1[a]) - 1].se + 1 << "\n";
            b = edge1[a][sz(edge1[a]) - 1].fi;
            edge1[a].pop_back();

            //cout << a << " " << b << endl;
            //re 0;
            unite(a, b);
            /*for (int i = 0; i < sz(edge1[a]); i++) {
                if (get_root(edge1[a][i].fi) != a) {
                    cout << edge1[a][i].fi + 1 << " " << edge1[a][i].se + 1;
                    unite(a, edge1[a][i].fi);
                    break;
                }
            }*/
        }
    }
    return 0;
}