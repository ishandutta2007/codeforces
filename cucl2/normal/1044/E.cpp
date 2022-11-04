#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
int a[22][22];
vector<vector<int> > vs;

void inline doit(const vector<pair<int, int> > vi) {
    int vt = a[vi.back().first][vi.back().second];
    vector<int> res;
    loop(i, SZ(vi)) {
        res.pub(a[vi[i].first][vi[i].second]);
        swap(a[vi[i].first][vi[i].second], vt);
    }
    vs.pub(res);
}

void inline movl(int x, int y) { doit({{x, y}, {x, y - 1}, {x == n ? x - 1 : x + 1, y - 1}, {x == n ? x - 1 : x + 1, y}}); }
void inline movr(int x, int y) { doit({{x, y}, {x, y + 1}, {x == n ? x - 1 : x + 1, y + 1}, {x == n ? x - 1 : x + 1, y}}); }
void inline movu(int x, int y) { doit({{x, y}, {x - 1, y}, {x - 1, y == m ? y - 1 : y + 1}, {x, y == m ? y - 1 : y + 1}}); }
void inline movd(int x, int y) { doit({{x, y}, {x + 1, y}, {x + 1, y == m ? y - 1 : y + 1}, {x, y == m ? y - 1 : y + 1}}); }

void inline mov2(int x, int y) {
    // A == (x, y)
    // A . => A B
    // . B => . .
    if (x != n - 1) {
        movd(x, y);     // . B / A . / . .
        movd(x + 1, y); // . B / . . / A .
        movl(x, y + 1); // B . / . . / A .
        movu(x + 2, y); // B . / A . / . .
        movu(x + 1, y); // A B / . . / . .
    }
    else {
        movr(x, y);     // . A . / B . .
        movr(x, y + 1); // . . A / B . .
        movu(x + 1, y); // B . A / . . .
        movl(x, y + 2); // B A . / . . .
        movl(x, y + 1); // A . . / B . .
    }
}

int inline should(int x, int y) {
    return (x - 1) * m + y;
}

pair<int, int> inline findpos(int val) {
    cont(i, n) cont(j, m) if (a[i][j] == val) return mak(i, j);
    return mak(-1, -1);
}

int main() {
    scanf("%d%d", &n, &m);
    cont(i, n) cont(j, m) scanf("%d", a[i] + j);
    // Lines except last two lines
    cont(i, n - 2) {
        cont(j, m - 1) {
            int x, y; tie(x, y) = findpos(should(i, j));
            while (y < j) movr(x, y++);
            while (y > j) movl(x, y--);
            while (x > i) movu(x--, y);
        }
        int x, y; tie(x, y) = findpos(should(i, m));
        if (x == i && y == m) continue;
        while (y < m) movr(x, y++);
        while (x > i + 1) movu(x--, y);
        mov2(i, m - 1);
    }
    // Last two lines, columes except last two columes
    cont(j, m - 2) {
        int x2, y2; tie(x2, y2) = findpos(should(n, j));
        if (x2 == n - 1) movd(x2++, y2);
        while (y2 > j) movl(x2, y2--);
        int x1, y1; tie(x1, y1) = findpos(should(n - 1, j));
        if (x1 == n - 1 && y1 == j) continue;
        if (x1 == n) movu(x1--, y1);
        while (y1 > j) movl(x1, y1--);
        mov2(n - 1, j);
    }
    // Last two lines, last two columes
    auto swap3 = [&] (int x1) {
        int x2 = 2 * n - 1 - x1;
        movl(x1, m);
        movl(x1, m - 1);
        doit({{x1, m - 2}, {x1, m - 1}, {x1, m}, {x2, m}, {x2, m - 1}, {x2, m - 2}});
    };
    if (abs(a[n - 1][m - 1] - a[n][m]) == 1) swap3(n);
    if (abs(a[n - 1][m] - a[n][m]) == 1) {
        if (a[n - 1][m] < a[n - 1][m - 1]) movu(n, m);
        else movd(n - 1, m);
    } else {
        if (a[n - 1][m] > a[n][m]) movu(n, m), movu(n, m);
    }
    if (a[n - 1][m] < a[n - 1][m - 1]) swap3(n - 1);
    if (a[n][m] < a[n][m - 1]) swap3(n);
    printf("%d\n", SZ(vs));
    parse(v, vs) {
        printf("%d", SZ(v));
        parse(it, v) printf(" %d", it);
        puts("");
    }
    return 0;
}