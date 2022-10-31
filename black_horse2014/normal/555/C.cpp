#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define X first
#define Y second
#define pb push_back
#define INF int(1e9)
#define MN 200005

const int NN = 524288;
template<class T>
inline void chkmin(T &x, T y) {
    if (y < x) x = y;
}

template<class T>
inline void chkmax(T &x, T y) {
    if (x < y) x = y;
}

template<class T>
struct WinnerTree {
    int n;
    T a[NN];

    WinnerTree(int m = 0) { for (n = 1; n < m; n <<= 1); }

    void build_min1(int m) {
        for (n = 1; n < m; n <<= 1);
        memset(a, 0x7F, sizeof a);
        for (int i = n; i < 2 * n; i++) a[i] = INF;
        for (int i = n - 1; i > 0; i--) a[i] = min(a[i + i], a[i + i + 1]);     
    }

    void build_min(int m, T *b) {

        for (n = 1; n < m; n <<= 1);
        memset(a, 0x7F, sizeof a);

        for (int i = n; i < n + m; i++) a[i] = b[i - n];
        for (int i = n - 1; i > 0; i--) a[i] = min(a[i + i], a[i + i + 1]);
    }

    void build_max1(int m) {

        for (n = 1; n < m; n <<= 1);
        memset(a, 0x80, sizeof a);

        for (int i = n; i < 2 * n; i++) a[i] = -1;
        for (int i = n - 1; i > 0; i--) a[i] = max(a[i + i], a[i + i + 1]);
    }

    void update_min(int s, T x) {
        if (x < a[s]) for (a[s] = x, s >>= 1; s; s >>= 1) a[s] = min(a[2 * s], a[2 * s + 1]);
    }

    void update_max(int s, T x) {
        if (a[s] < x) for (a[s] = x, s >>= 1; s; s >>= 1) a[s] = max(a[2 * s], a[2 * s + 1]);
    }

    T get_min(int s, int e) {
        if (e == s + 1) return a[s];
        if (e == s + 2) return min(a[s], a[s + 1]);
        T res = get_min((s + 1) >> 1, e >> 1);
        if (s & 1) chkmin(res, a[s]);
        if (e & 1) chkmin(res, a[e - 1]);
        return res;
    }

    T get_max(int s, int e) {
        if (e == s + 1) return a[s];
        if (e == s + 2) return max(a[s], a[s + 1]);
        T res = get_max((s + 1) >> 1, e >> 1);
        if (s & 1) chkmax(res, a[s]);
        if (e & 1) chkmax(res, a[e - 1]);
        return res;
    }

    T min_query(int s, int e) {
        return get_min(n + s, n + e);
    }

    T max_query(int s, int e) {
        return get_max(n + s, n + e);
    }

};
WinnerTree<int> Tree[2];

int N, Q;
int x[MN], y[MN], str[MN][3];
int xx[MN], yy[MN], xn, yn;
int xxchk[MN], yychk[MN];

int main() {
    
    int i, j, k, st, en, mid;
    
    scanf("%d%d", &N, &Q);
    for (i = 0; i < Q; i++) {
        scanf("%d%d%s", x + i, y + i, str[i]);
        xx[i] = x[i], yy[i] = y[i];
    }
    xx[Q] = 1;
    yy[Q] = 1;
    sort(xx, xx + Q + 1);
    sort(yy, yy + Q + 1);
    xn = unique(xx, xx + Q + 1) - xx;
    yn = unique(yy, yy + Q + 1) - yy;
    for (i = 0; i < Q; i++) {
        x[i] = lower_bound(xx, xx + xn, x[i]) - xx;
        y[i] = lower_bound(yy, yy + yn, y[i]) - yy; 
    }
    Tree[0].build_min1(xn);
    Tree[1].build_min1(yn);
    for (i = 0; i < Q; i++) {
        if (xxchk[x[i]] || yychk[y[i]]) {
            puts("0");
            continue; 
        }
        if (str[i][0] == 'U') {
            st = -1, en = y[i] + 1;
            while (en - st > 1) {
                mid = (st + en) / 2;
                int t = Tree[0].get_min(Tree[0].n + mid, Tree[0].n + y[i] + 1);
                if (t > x[i]) en = mid;
                else st = mid;
            }
            Tree[1].update_min(Tree[1].n + x[i], en);
            printf("%d\n", yy[y[i]] - yy[en - 1]);
        } else {
            st = -1, en = x[i] + 1;
            while (en - st > 1) {
                mid = (st + en) / 2;
                int t = Tree[1].get_min(Tree[1].n + mid, Tree[1].n + x[i] + 1);
                if (t > y[i]) en = mid;
                else st = mid;
            }
            Tree[0].update_min(Tree[0].n + y[i], en);
            printf("%d\n", xx[x[i]] - xx[en - 1]);                      
        }
        xxchk[x[i]] = yychk[y[i]] = 1;
    }
    
    return 0;   
}