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

const int max_n = 2e5;
const int max_sqn = 500;

int n, m, sqn;
char c[2][max_n + 1];

vector<int> sqr_pos;
int dist_to_next[max_sqn][2][2];

int dp[max_sqn][2][max_sqn][2];

int segs[max_n];

pair<int, int> get_normal_coords(int x)
{
    return make_pair(x / n, x % n);
}

int bf_smallest_path(int i1, int j1, int i2, int j2)
{
    if (c[i1][j1] == 'X' || c[i2][j2] == 'X') return -1;
    if (j2 < j1) {
        swap(i1, i2);
        swap(j1, j2);
    }
    
    int res = 0;
    while (j1 != j2) {
        if (c[i1][j1 + 1] != 'X') {
            ++res;
            ++j1;
        } else {
            if (c[i1 ^ 1][j1] == 'X') {
                return -1;
            } else {
                ++res;
                i1 ^= 1;
                if (c[i1][j1 + 1] == 'X') {
                    return -1;
                } else {
                    ++res;
                    ++j1;
                }
            }
        }
    }
    
    return res + (i1 != i2);
}

pair<int, int> bf_smallest_path_to_pair(int i1, int j1, int j2)
{
    if (c[i1][j1] == 'X') return make_pair(-1, -1);
    
    int adder = +1;
    if (j2 < j1) {
        adder = -1;
    }
    
    int res = 0;
    while (j1 != j2) {
        if (c[i1][j1 + adder] != 'X') {
            ++res;
            j1 += adder;
        } else {
            if (c[i1 ^ 1][j1] == 'X') {
                return make_pair(-1, -1);
            } else {
                ++res;
                i1 ^= 1;
                if (c[i1][j1 + adder] == 'X') {
                    return make_pair(-1, -1);
                } else {
                    ++res;
                    j1 += adder;
                }
            }
        }
    }
    
    return make_pair(res + (i1 != 0), res + (i1 != 1));
}

inline void update(int& x, int y)
{
    if (y != -1 && (x == -1 || y < x)) 
        x = y;
}

inline void add(int& x, int y)
{
    if (y == -1 || x == -1) {
        x = -1;
    } else {
        x += y;
    }
}

int smallest_path(pair<int, int> v1, pair<int, int> v2)
{
    if (v1.second == v2.second) return (v1.first != v2.first);
    if (v2.second < v1.second) swap(v1, v2);
    
    int s1 = segs[v1.second];
    int s2 = segs[v2.second];
    
    if (s1 == s2) {
        return bf_smallest_path(v1.first, v1.second, v2.first, v2.second);
    }

    int res[2][2];
    
    pair<int, int> temp = bf_smallest_path_to_pair(v1.first, v1.second, sqr_pos[s1 + 1]);
    res[0][0] = temp.first;
    res[0][1] = temp.second;
    
    temp = bf_smallest_path_to_pair(v2.first, v2.second, sqr_pos[s2]);
    res[1][0] = temp.first;
    res[1][1] = temp.second;

    int Ares = -1;
    
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j) {
            int val = res[0][i];
            add(val, dp[s1 + 1][i][s2][j]);
            add(val, res[1][j]);
            update(Ares, val);
        }
    
    return Ares;
}

void pre_calc()
{
    sqn = sqrt(n);
    
    sqr_pos.push_back(0);
    while (sqr_pos.back() + sqn < n) {
        sqr_pos.push_back(sqr_pos.back() + sqn);
    }
    
    /*
    cout << "sqr_pos = " << endl;
    cout << "  ";
    for (int i = 0; i < (int) sqr_pos.size(); ++i)
        cout << sqr_pos[i] << " ";
    cout << endl;
    */
    
    for (int id = 0; id + 1 < (int) sqr_pos.size(); ++id)
        for (int i1 = 0; i1 < 2; ++i1)
            for (int i2 = 0; i2 < 2; ++i2) {
                dist_to_next[id][i1][i2] = bf_smallest_path(i1, sqr_pos[id], i2, sqr_pos[id + 1]);
            }
    
    /*
    cout << "dist_to_next = " << endl;
    for (int i = 0; i < (int) sqr_pos.size(); ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                cout << "  <" << i << ", " << j << ", " << k << "> = " << dist_to_next[i][j][k] << endl;
    cout << endl;
    */
    
    for (int s = 0; s < (int) sqr_pos.size(); ++s) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                dp[s][i][s][j] = bf_smallest_path(i, sqr_pos[s], j, sqr_pos[s]);
        for (int t = s + 1; t < (int) sqr_pos.size(); ++t) {
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    dp[s][i][t][j] = -1;
            for (int i = 0; i < 2; ++i)
                for (int j = 0; j < 2; ++j)
                    for (int k = 0; k < 2; ++k) {
                        int val = dp[s][i][t - 1][j];
                        add(val, dist_to_next[t - 1][j][k]);
                        update(dp[s][i][t][k], val);
                    }
        }
    }
    
    for (int i = 0, j = 0; i < n; ++i) {
        while (j + 1 < (int) sqr_pos.size() && sqr_pos[j + 1] <= i) ++j;
        segs[i] = j;
    }
    
    /*
    cout << "segs = " << endl;
    for (int i = 0; i < n; ++i)
        cout << "  " << i << ": " << segs[i] << endl;
    cout << endl;
    */
}

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    srand(time(NULL));
    printf("%d %d\n", max_n, max_n);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < max_n; ++j) {
            printf(".");
        }
        printf("\n");
    }
    for (int i = 0; i < max_n; ++i) {
        printf("%d %d\n", rand() % (2 * max_n) + 1, rand() % (2 * max_n) + 1);
    }
    return 0;
    */
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d\n", &n, &m);
    scanf("%s\n%s\n", c[0], c[1]);

    pre_calc();

    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1; --v2;
        printf("%d\n", smallest_path(get_normal_coords(v1), get_normal_coords(v2)));
    }

    return 0;
}