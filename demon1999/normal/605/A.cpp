#include <iostream>
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
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
#define x1 x11
#define x2 x22
#define y1 y11
#define y2 y22
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1000000007, ma = 131072 * 2;
int k, m = 1, n, pos[100000];
vector<int> a;

int main(){
    iostream::sync_with_stdio(0);
    //freopen("travel.in", "r",  stdin);
    //freopen("travel.out", "w", stdout);
    cin >> n;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
        pos[a[i] - 1] = i;
    }
    int k = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i - 1]) {
            k++;
        }
        else k = 1;
        m = max(m, k);
    }
    cout << n - m;
    return 0;
}