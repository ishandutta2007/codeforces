#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 301;

int a[max_n][max_n];
int n, m, t, tu, tp, td;

inline int go_value(int from, int to)
{
    if (from == to) return tp;
    if (from > to) return td;
    return tu;
}

int str_r[max_n][max_n];
int str_l[max_n][max_n];

int stl_u[max_n][max_n];
int stl_d[max_n][max_n];

inline int get_str_r(int str, int l, int r)
{
    return str_r[str][l] - str_r[str][r];
}

inline int get_str_l(int str, int l, int r)
{
    return str_l[str][r] - str_l[str][l];
}

inline int get_stl_u(int stl, int u, int d)
{
    return stl_u[d][stl] - stl_u[u][stl];
}

inline int get_stl_d(int stl, int u, int d)
{
    return stl_d[u][stl] - stl_d[d][stl];
}

inline int get_sum1(int left, int right, int down)
{
    return get_str_l(down, left, right) + 
            get_stl_u(left, 0, down) +
            get_stl_d(right, 0, down);
}

const int max_val = 2e5;

int values[max_n];
int ids[max_val];

int ans_value = -1;
int ans_left;
int ans_right;
int ans_down;
int ans_up;

void update_ans(int _ans_value, int _ans_left, int _ans_right, int _ans_up, int _ans_down)
{
    _ans_value = abs(_ans_value - t);
    if (ans_value == -1 || _ans_value < ans_value) {
        ans_value = _ans_value;
        ans_left = _ans_left;
        ans_right = _ans_right;
        ans_down = _ans_down;
        ans_up = _ans_up;
    }
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &m, &t);
    
    scanf("%d%d%d", &tp, &tu, &td);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; ++i) {
        str_r[i][m - 1] = 0;
        for (int j = m - 2; j >= 0; --j) {
            str_r[i][j] = str_r[i][j + 1] + go_value(a[i][j], a[i][j + 1]);
        }
        
        str_l[i][0] = 0;
        for (int j = 1; j < m; ++j) {
            str_l[i][j] = str_l[i][j - 1] + go_value(a[i][j], a[i][j - 1]);
        }
    }
    
    for (int j = 0; j < m; ++j) {
        stl_u[0][j] = 0;
        for (int i = 1; i < n; ++i) {
            stl_u[i][j] = stl_u[i - 1][j] + go_value(a[i][j], a[i - 1][j]);
        }
        
        stl_d[n - 1][j] = 0;
        for (int i = n - 2; i >= 0; --i) {
            stl_d[i][j] = stl_d[i + 1][j] + go_value(a[i][j], a[i + 1][j]);
        }
    }
    
    for (int i = 0; i < max_val; ++i) ids[i] = -1;
    
    set<int> s;
    set<int>::iterator itr;
    
    for (int left = 0; left < m; ++left)
        for (int right = left + 2; right < m; ++right) {
            for (int down = 0; down < n; ++down) 
                values[down] = get_sum1(left, right, down);
            for (int down = 1; down < n; ++down) {
                if (ids[values[down]] == -1) {
                    s.insert(values[down]);
                }
                ids[values[down]] = down;
            }
            for (int up = 0; up + 2 < n; ++up) {
                if (ids[values[up + 1]] == up + 1) {
                    s.erase(values[up + 1]);
                    ids[values[up + 1]] = -1;
                }
                int ct = get_str_r(up, left, right) -
                        get_stl_u(left, 0, up) -
                        get_stl_d(right, 0, up);
                int tt = t - ct;
                itr = s.lower_bound(tt);
                
                if (itr != s.end()) {
                    int x = (*itr);
                    
                    update_ans(ct + x, left, right, up, ids[x]);
                }
                
                if (itr != s.begin()) {
                    --itr;
                    
                    int x = (*itr);
                    
                    update_ans(ct + x, left, right, up, ids[x]);
                }
            }
            s.erase(values[n - 1]);
            ids[values[n - 1]] = -1;
        }   
        
    printf("%d %d %d %d\n", ans_up + 1, ans_left + 1, ans_down + 1, ans_right + 1);
        
    return 0;
}