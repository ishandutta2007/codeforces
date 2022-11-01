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
ll n, k, ans[5100][5100], p, p1, ansss;
vector<ll> a;
int main(){
    //ifstream cin("input.txt");
    iostream::sync_with_stdio(0);
    cin >> n >> k;
    p = n / k;
    p1 = p;
    if (n % k) p1++;
    a.resize(n);
    forn (i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ans[1][0] = a[p - 1] - a[0];
    ansss = ans[1][0];
    if (p1 - 1 < n) {
        ans[1][1] = a[p1 - 1] - a[0];
        ansss = ans[1][1];
    }
    for (int i = 2; i <= k; i++) {
        for (int j = i * p; j <= min(i * p1, n); j++) {
                ans[i][j - i * p] = 1000000000000000000;
            if (j - p <= (i - 1) * p1) ans[i][j - i * p] = ans[i - 1][j - i * p] + a[j - 1] - a[j - p];
            if (j - (i - 1) * p - p1 >= 0)
                ans[i][j - i * p] = min(ans[i][j - i * p], ans[i - 1][j - (i - 1) * p - p1] + a[j - 1] - a[j - p1]);
            ansss = ans[i][j - i * p];
        }
    }
    cout << ansss;
    return 0;
}