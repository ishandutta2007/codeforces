#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) a.size()
#define re  return
#define fi first
#define se second
#define l1 l11
#define l2 l22
typedef long long ll;
typedef long double ld;
using namespace std;
const ll mod = 1000000007;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("point.in", "r", stdin);
    cin >> n;
    vector<int> p;
    forn (i, n) {
        p.push_back(1);
        while (sz(p) >= 2 && p[sz(p) - 1] == p[sz(p) - 2]) {
            p.pop_back();
            p[sz(p) - 1]++;
        }
    }
    forn (i, sz(p)) cout << p[i] << " ";
    return 0;
}