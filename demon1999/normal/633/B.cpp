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
//#define int long long

typedef long long ll;
typedef long double ld;
using namespace std;
int n;


signed main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qq.in", "r",  stdin));
    //freopen(".out", "w", stdout);
    int m, k = 0;
    cin >> m;
    vector<int> jj;
    for (int i = 1; i <= m * 10; i++) {
        int q = 0, p = 5;
        while (p <= i) {
            q += i / p;
            p *= 5;
        }
        if (q == m){ k++; jj.push_back(i);}
    }
    cout << k << endl;
    forn (i, k) cout << jj[i] << " ";
    return 0;
}