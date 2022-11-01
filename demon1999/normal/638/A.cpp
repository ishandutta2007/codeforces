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
ll n, m, a, b, c, k;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("qqq.in", "r",  stdin);
    cin >> n >> k;
    if (k % 2) {
        cout << k / 2 + 1;
    }
    else
        cout << (n - k) / 2 + 1;
    return 0;
}