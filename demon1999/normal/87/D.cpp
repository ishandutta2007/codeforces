#include <bits/stdc++.h>
//#include "grader.h"
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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


const ll mod = 998244353;
struct st{
    int a, b, d, nu;
};
const ll ma = 4 * 128 * 1024;
int n, k, m, a, b, we, ans, sz1[ma], pr[ma], centr[ma];
ll use[ma], q22 = 1;
vector<pair<int, int> > edge[ma];
vector<st> qq, pp[ma];
vector<pair<ll, int> > cc;

bool cmp(st a, st b) {
    re a.d < b.d;
}

int get_root(int a) {
    if (pr[a] == a) re a;
    pr[a] = get_root(pr[a]);
    re pr[a];
}

void unite1(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (sz1[a] < sz1[b]) swap(a, b);
    pr[b] = a;
    sz1[a] += sz1[b];
}

ll dfs(int nu, int pr, ll szz) {
    //cout << nu << " " << pr << " " << szz << endl;
    ll k = sz1[nu], c;
    for (auto v : edge[nu]) {
        if (v.fi != pr) {
            c = dfs(v.fi, nu, szz);
            k += c;
            //cout << v.se << " " << c << " " << szz - c << endl;
            cc.push_back(mp(c * (szz - c), v.se));
        }
    }
    re k;
}

int dfs1(int nu, int pr) {
    use[nu] = q22;
    ll k = sz1[nu], c;
    for (auto v : edge[nu]) {
        if (v.fi != pr) {
            c = dfs1(v.fi, nu);
            k += c;
        }
    }
    re k;
}

bool cmp1(pair<ll, int> a, pair<ll, int> b) {
    re a.fi > b.fi || (a.fi == b.fi && a.se < b.se);
}

int main() {
	//ifstream cin("input.txt");
	cin >> n;
	qq.resize(n - 1);
    forn (i, n - 1) {
        cin >> qq[i].a >> qq[i].b >> qq[i].d;
        qq[i].a--; qq[i].b--;
        qq[i].nu = i + 1;
    }
    sort(qq.begin(), qq.end(), cmp);
    int k = 1;
    forn (i, n) {
        pr[i] = i;
        sz1[i] = 1;
    }
    forn (i, n - 1) {
        if (i && qq[i].d > qq[i - 1].d) k++;
        pp[k - 1].push_back(qq[i]);
    }
    forn (i, k) {
        for (st v : pp[i]) {
            edge[get_root(v.a)].resize(0);
            edge[get_root(v.b)].resize(0);
            //cout << v.a << " " << v.b << " " << get_root(v.a) << " " << get_root(v.b) << endl;
        }
        //cout << endl;
        int szz = 0;
        for (st v : pp[i]) {
            edge[get_root(v.a)].push_back(mp(get_root(v.b), v.nu));
            if (sz(edge[get_root(v.a)]) == 1)
                szz += sz1[get_root(v.a)];
            edge[get_root(v.b)].push_back(mp(get_root(v.a), v.nu));
            if (sz(edge[get_root(v.b)]) == 1)
                szz += sz1[get_root(v.b)];
        }
        for (st v : pp[i]) {
            if (use[get_root(v.a)] != q22) {
                dfs(get_root(v.a), -1, dfs1(get_root(v.a), -1));
            }
        }
        q22++;

        for (st v : pp[i])
            unite1(v.a, v.b);
    }
    sort(cc.begin(), cc.end(), cmp1);
    cout << 2LL * cc[0].fi << " ";
    k = 0;
    forn (i, sz(cc))
        if (cc[i].fi == cc[0].fi) k++;
    cout << k << "\n";
    forn (i, sz(cc))
        if (cc[i].fi == cc[0].fi) cout << cc[i].se << " ";
    return 0;
}