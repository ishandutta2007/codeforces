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

const int ma = 2 * 131072;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("qqq.in", "w",  stdout);
    int a, b;
    cin >> a >> b;
    cout << 6 - a - b;
    return 0;
}