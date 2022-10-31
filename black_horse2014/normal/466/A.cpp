#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>

#include <bitset>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

template<class T>
inline void chkmax(T& x, T y) {
    if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
    if (y < x) x = y;
}

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(x) int((x).size())
#define bit(x) (1 << (x))

#define INF 100000000

main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int n, m, a, b, x, y, rlt;
    
    scanf("%d%d%d%d", &n, &m, &a, &b);
    rlt = INF;
    for (x = 0; x <= n; x++) {
        y = (n - x + m - 1) / m;
        chkmin(rlt, x * a + y * b);
    }
    printf("%d\n", rlt);
}