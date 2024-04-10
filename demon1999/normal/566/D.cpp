#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) (int)a.size()
#define re  return
#define vv vector
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;
int bb, a, l, r, n, m, dsu[200000], sz1[200000], sum;

int root(int a) {
    if (a == dsu[a]) re a;
    dsu[a] = root(dsu[a]);
    re dsu[a];
}

void union1(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) re;
    if (sz1[a] > sz1[b]) {
        dsu[b] = a;
        sz1[a] += sz1[b];
    }
    else {
        dsu[a] = b;
        sz1[b] += sz1[a];
    }
}

set<int> a1;
set<int> :: iterator it;
vector<int> p;
int main(){
    //freopen("input.txt", "r", stdin);
    //ifstream cin("input.txt");
    //iostream::sync_with_stdio(0);
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    forn (i, n)
        dsu[i] = i, sz1[i] = 1,
        a1.insert(i);
    forn (i, m) {
        scanf("%d%d%d", &a, &l, &r);
        //cin >> a >> l >> r;
        l--;
        r--;
        if (a == 1) {
            union1(l, r);
        }
        if (a == 3) {
            if (root(l) != root(r))
                printf("NO\n");
            else
                printf("YES\n");
        }
        if (a == 2) {
            it = --a1.upper_bound(l);
            l = *it;
            it++;
            p.resize(0);
            while (it != a1.end() && *it <= r) {
                union1(*it, l);
                p.push_back(*it);
                it++;
            }
            forn (i, sz(p))
                a1.erase(p[i]);
            a1.insert(l);
        }
    }
    re 0;
}