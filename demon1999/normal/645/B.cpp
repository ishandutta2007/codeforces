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

struct T { int x, y; };
T t = {1, 2};

vector<int> a;
string s, s1;
char c0, c1, c2, c3;
const int ma = 131072 * 2;
ll segtr[2 * ma];

ll sum(ll l, ll r) {
    if (l > r) re 0;
    if (l % 2) {
        re segtr[l] + sum(l + 1, r);
    }
    if (r % 2 == 0) {
        re segtr[r] + sum(l, r - 1);
    }
    re sum(l / 2, r / 2);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
//    assert(freopen("qqq.in", "r",  stdin));
    ll n, k, ans = 0;
    cin >> n >> k;
    forn (i, n) a.push_back(i);
    for (int i = 0; i < min(n / 2, k); i++) {
        swap(a[i], a[n - i - 1]);
    }
    for (int i = 0; i < n; i++) {
        ans += sum(a[i] + ma, 2 * ma - 1);
        int j = a[i] + ma;
        while (j) {
            segtr[j]++;
            j /= 2;
        }
    }
    cout << ans;
    return 0;
}