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
#define forn(i, n) for(ll i = 0; i < int(n); i++)
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
const ll ma = 131072 * 2;
ll segtr[2 * ma];
ll n, k, ans = 1000000000;

ll fc(int l, int r) {
    if (l > r) re 0;
    if (l % 2) {
        re segtr[l] + fc(l + 1, r);
    }
    if (r % 2 == 0)
        re segtr[r] + fc(l, r - 1);
    re fc(l / 2, r / 2);
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
//    assert(freopen("qqq.in", "r",  stdin));

    cin >> n >> k;
    string s;
    cin >> s;
    forn (i, n) {
        segtr[i + ma] = 1 - s[i] + '0';
    }
    for (int i = ma - 1; i > 0; i--)
        segtr[i] = segtr[2 * i] + segtr[2 * i + 1];
    forn (i, n) {
        if (segtr[i + ma] == 0) continue;
        ll l = 0, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (fc(max(ma, i - mid + ma), i + ma - 1) + fc(i + ma + 1, min(i + mid + ma, 2 * ma - 1)) >= k) {
                r = mid;
            }
            else l = mid;
        }
        ans = min(ans, r);
    }
    cout << ans;
    return 0;
}