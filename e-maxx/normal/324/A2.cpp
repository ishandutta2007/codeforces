#pragma comment (linker, "/STACK:200000000")
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 310 * 1000;

int n, a[MAXN];


bool read() {
    if (!(cin >> n))
        return false;
    forn(i, n)
        scanf("%d", &a[i]);
	return true;
}


void solve() {
    int64 ans = -INF64;
    vector<int> vec;

    int ans_left = -1,  ans_right = -1;
    vector<int> neg;
    map<int, int64> sums;
    map<int, int> where;
    int64 sum = 0;
    forn(i, n) {
        if (sums.count(a[i])) {
            int64 cans = sum + a[i] - sums[a[i]];
            if (a[i] < 0)
                cans += a[i];
            if (cans > ans) {
                ans = cans;
                ans_left = where[a[i]];
                ans_right = i;
            }
        }
        if (!sums.count(a[i]) || sum < sums[a[i]]) {
            sums[a[i]] = sum;
            where[a[i]] = i;
        }
        if (a[i] >= 0)
            sum += a[i];
        else
            neg.push_back(i);
    }
    forn(i, ans_left)
        vec.push_back(i);
    fore(i, ans_right + 1, n)
        vec.push_back(i);
    forn(i, neg.size())
        if (neg[i] != ans_left && neg[i] != ans_right)
            vec.push_back(neg[i]);

    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    cout << ans << ' ' << vec.size() << endl;
    forn(i, vec.size())
        printf("%d ", vec[i] + 1);
    puts("");
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	while (read())
		solve();
#else
	if (!read())  throw;
	solve();
#endif
}