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

typedef unsigned long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(x) int((x).size())
#define bit(x) (1 << (x))

#define MX 25
#define rep(i, n) for (int i = 0; i < n; i++)

int a[MX], n;
LL d[MX], sum[MX], b[MX], A, B;
LL st, en, mid;

LL calc(int n) {
    if (n == 0) return a[0] * (a[0] + 1) / 2;
    LL rlt(0LL);
    rlt += a[n] * sum[n];
    rlt += a[n] * (a[n] - 1) / 2 * d[n];
    rlt += a[n] * (b[n] + 1);
    rlt += calc(n - 1);
    return rlt;
}

LL get(LL v) {
    if (!v) return 0LL;
    n = 0;
    while (v) a[n++] = v % 10, v /= 10;
    b[0] = 0;
    for (int i = 1; i < n; i++) b[i] = b[i - 1] + a[i - 1] * d[i - 1];
    return calc(n - 1);
}

main() {
    int i, k;
    d[0] = 1LL;
    for (i = 1; i < MX; i++) d[i] = d[i - 1] * 10LL;
    for (i = 1; i < MX; i++) sum[i] = 45 * i * d[i - 1];    
    cin >> A;
    
    for (i = 1; ; i++) {
        B = A + get(i - 1); 
        for (k = 1; ; k++) if (sum[k] >= B) break;
        en = d[k];
        st = i;
        if (st < d[k - 1]) st = d[k - 1];
        
        while (st < en) {
            mid = (st + en) / 2;
            if (get(mid) >= B) en = mid;
            else st = mid + 1;  
        }
        if (get(st) == B) break;
    } 
    cout << i << ' ' << st << endl;
}