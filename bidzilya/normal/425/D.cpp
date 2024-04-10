#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;

const int max_n = 1e5;
const int max_x = 1e5;

int n, sqn;
pair<int, int> p[max_n];
int marked[max_n];

vector<vector<int> > a;

int ans = 0;

bool is_point(int x, int y)
{
    if (a[x].empty()) return false;
    int lf = 0, rg = a[x].size() - 1;
    while (lf <= rg) {
        int md = (lf + rg) >> 1;
        int id = a[x][md];
        if (p[id].second == y) return true;
        if (p[id].second < y) {
            lf = md + 1;
        } else {
            rg = md - 1;
        }
    }
    return false;
}

void find_ans()
{
    sort(p, p + n);
    memset(marked, 0, sizeof(marked));
    a.clear();
    a.resize(max_x + 1);
    for (int i = 0; i < n; ++i) 
        a[p[i].first].push_back(i);
    sqn = sqrt(n);
    for (int i = 0; i <= max_x; ++i) {
        int sz = a[i].size();
        if (sz <= sqn) {
            for (int i1 = 0; i1 < sz; ++i1)
                for (int i2 = i1 + 1; i2 < sz; ++i2) {
                    int id1 = a[i][i1];
                    int id2 = a[i][i2];
                    int y1 = p[id1].second;
                    int y2 = p[id2].second;
                    int d = y2 - y1;
                    if (i - d >= 0) {
                        if ((int) a[i - d].size() > sqn) {
                            if (is_point(i - d, y1) && is_point(i - d, y2)) ++ans;
                        }
                    }
                    if (i + d <= max_x) {
                        if (is_point(i + d, y1) && is_point(i + d, y2)) ++ans;
                    }
                }
            for (int j = 0; j < sz; ++j)
                marked[a[i][j]] = 1;
        }
    }
    int nn = n;
    n = 0;
    for (int i = 0; i < nn; ++i)
        if (!marked[i]) {
            p[n] = p[i];
            ++n;
        }
}

int main()
{
//    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    sqn = sqrt(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    
    find_ans();
    for (int i = 0; i < n; ++i)
        swap(p[i].first, p[i].second);
    find_ans();

    printf("%d\n", ans);

    return 0;
}