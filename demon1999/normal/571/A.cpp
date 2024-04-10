#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
//#include "grader.h"
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define rs(a, j) a.resize(j)
#define pb(a, j) a.push_back(j)
#define pp(a) a.pop_back()
#define len(s) s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;
const int ma = 1024, mi = 200000000;
ll a[3], ans, l, mk;
ll c(ll k, ll n) {
    re n * (n - 1) / 2;
}
int main(){
    //ifstream cin("input.txt");
    //iostream::sync_with_stdio(0);
    cin >> a[0] >> a[1] >> a[2] >> l;
    for (int i = 0; i <= l; i++) {
        mk = a[0] + a[1] + a[2] + i;
        if (mk % 2)mk++;
        mk /= 2;
        ans += c(2, i + 2);
        for (int j = 0; j < 3; j++)
            if (i - mk + min(mk, a[j]) >= 0)
                ans -= c(2, i - mk + min(mk, a[j]) + 2);
    }
    cout << ans;
    return 0;
}