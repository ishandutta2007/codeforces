#include <cstdio>
#include <vector>
static const int MAXN = 500006;
static const int MAXC = 1000006;
inline int getint() {
    static int ret;
    static char ch;
    while ((ch = getchar()) < '0' || ch > '9');
    ret = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') ret = ret * 10 + ch - '0';
    return ret;
}

int n, c, li;
std::vector<int> w[MAXN];

namespace fwk {

int t[MAXC] = { 0 };
// mdzz TUT Fenwick trees are not needed...
inline void add(int pos, int inc) { t[pos] += inc; }
inline int at(int pos) { return t[pos]; }

}

int main()
{
    n = getint(); c = getint();
    for (int i = 0; i < n; ++i) {
        li = getint(); w[i].reserve(li);
        for (int j = 0; j < li; ++j) w[i].push_back(getint() - 1);
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < (int)w[i - 1].size() || j < (int)w[i].size(); ++j) {
            int a = (j < (int)w[i - 1].size() ? w[i - 1][j] : -1),
                b = (j < (int)w[i].size() ? w[i][j] : -1);
            if (a != b && a != -1) {
                if (b == -1) { puts("-1"); return 0; }
                if (a < b) {
                    fwk::add(c - b, +1);
                    fwk::add(c - a, -1);
                } else {
                    fwk::add(0, +1);
                    fwk::add(c - a, -1);
                    fwk::add(c - b, +1);
                    fwk::add(c, -1);
                }
                break;
            } else if (a == -1) break;
        }
    }

    int sum = 0;
    for (int i = 0; i < c; ++i) {
        sum += fwk::at(i);
        if (sum == 0) { printf("%d\n", i); return 0; }
    }

    puts("-1");
    return 0;
}