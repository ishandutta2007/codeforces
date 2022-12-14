#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
    int x, y, id;
    bool operator<(const point &o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
};

vector<point> bu[2020][2020];
vector<int> sl;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        point p;
        scanf("%d %d", &p.x, &p.y);
        p.id = i + 1;
        bu[p.x / 500][p.y / 500].push_back(p);
    }
    
    for (int i = 0; i < 2010; ++i) {
        for (int jj = 0; jj < 2010; ++jj) {
            int j = jj;
            if (i & 1) {
                j = 2009 - jj;
            }
            sort(bu[i][j].begin(), bu[i][j].end());
            for (int k = 0; k < (int) bu[i][j].size(); ++k) {
                sl.push_back(bu[i][j][k].id);
            }
        }
    }
    
    for (int i = 0; i < (int) sl.size(); ++i) {
        printf("%d%c", sl[i], " \n"[i == (int) sl.size() - 1]);
    }
    return 0;
}