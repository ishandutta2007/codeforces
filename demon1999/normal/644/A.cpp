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
int n, a, b, mas[100][100];
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen(".in", "r",  stdin));
    //freopen(".out", "w", stdout);
    cin >> n >> a >> b;
    int k = 1, p = 2;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if ((i + j) % 2 == 0 && k <= n) {
                mas[i][j] = k;
                k += 2;
            }
            if ((i + j) % 2 == 1 && p <= n) {
                mas[i][j] = p;
                p += 2;
            }
        }
    }
    if (k <= n || p <= n) {
        cout << -1;
        re 0;
    }
    forn (i, a) {
        forn (j, b) cout << mas[i][j] << " ";
        cout << endl;
    }
    return 0;
}