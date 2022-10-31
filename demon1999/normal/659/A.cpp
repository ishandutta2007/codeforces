#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;

using namespace std;

void my_assert(bool q) {
    if (!q) while(true);
}

int n, a, b;
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    cin >> n >> a >> b;
    a--;
    cout << ((a + b) % n + n) % n + 1;
    return 0;
}