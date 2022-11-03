#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int min(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int max(int a, int b)
{
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

const int max_n = 1e5;
const int max_log = 20;

int n;
int s, l;
int a[max_n];

int max_table[max_n][max_log];
int min_table[max_n][max_log];

int prelog[max_n + 1];

void ConstructPrelog()
{
    prelog[1] = 0;
    for (int i = 1; i <= max_n; ++i) {
        prelog[i] = prelog[i - 1];
        if ((1 << (prelog[i] + 1)) <= i) {
            ++prelog[i];
        }
    }
}

typedef int (*FuncType)(int, int);

void ConstructTable(int table[max_n][max_log], FuncType func)
{
    for (int i = 0; i < n; ++i) {
        table[i][0] = a[i];
    }
    
    for (int i = 1; i < max_log; ++i) {
        for (int j = 0; j < n; ++j) {
            table[j][i] = table[j][i - 1];
            if (j + (1 << (i - 1)) < n) {
                table[j][i] = func(table[j][i], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
}

int GetValueInTable(int table[max_n][max_log], FuncType func, int l, int r)
{
    int len = r - l + 1;
    
    int d = prelog[len];
    
    return func(table[l][d], table[r - (1 << d) + 1][d]);
}

int tree[4 * max_n];

const int INF = 1e9;

void Build(int v, int tl, int tr)
{
    if (tl == tr) {
        tree[v] = INF;
    } else {
        int tm = (tl + tr) >> 1;
        
        Build(2 * v, tl, tm);
        Build(2 * v + 1, tm + 1, tr);
        
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

int GetValueInTree(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return tree[v];
    } else {
        int tm = (tl + tr) >> 1;
        
        if (r <= tm) {
            return GetValueInTree(2 * v, tl, tm, l, r);
        } 
        if (l > tm) {
            return GetValueInTree(2 * v + 1, tm + 1, tr, l, r);
        }
        
        return min(GetValueInTree(2 * v, tl, tm, l, tm),
                    GetValueInTree(2 * v + 1, tm + 1, tr, tm + 1, r));
    }
}

void SetValueInTree(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr) {
        tree[v] = val;
    } else {
        int tm = (tl + tr) >> 1;
        
        if (pos <= tm) {
            SetValueInTree(2 * v, tl, tm, pos, val);
        } else {
            SetValueInTree(2 * v + 1, tm + 1, tr, pos, val);
        }
        
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
}

bool IsGoodRange(int left_pos, int right_pos)
{
    return right_pos - left_pos + 1 >= l && 
            GetValueInTable(max_table, max, left_pos, right_pos) -
            GetValueInTable(min_table, min, left_pos, right_pos) <= s;
}

int GetMaxPosToRight(int pos)
{
    int right_pos = pos + l - 1;
    
    if (right_pos >= n) {
        return -1;
    }
    
    if (!IsGoodRange(pos, right_pos)) {
        return -1;
    }
    
    int bl = right_pos;
    int br = n - 1;
    
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        
        if (IsGoodRange(pos, bm)) {
            right_pos = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    
    return right_pos;
}

int main()
{
    /*
    freopen("input.txt", "w", stdout);
    
    srand(time(NULL));
    
    cout << (int) 1e5 << " " << (int) 1e9 << " " << (int) 1e5 << endl;
    for (int i = 0; i < 1e5; ++i) {
        cout << rand() << " ";
    }
    
    return 0;
    */
    
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    cin >> s >> l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ConstructPrelog();
    ConstructTable(min_table, min);
    ConstructTable(max_table, max);
    
    Build(1, 0, n - 1);
    
    for (int i = n - 1; i >= 0; --i) {
        int jr = GetMaxPosToRight(i);
        
        if (jr == -1) {
            continue;
        }
        
        int jl = i + l - 1;
        
        if (jr == n - 1) {
            SetValueInTree(1, 0, n - 1, i, 1);
        } else {
            int r = GetValueInTree(1, 0, n - 1, jl + 1, jr + 1);
            if (r != INF) {
                SetValueInTree(1, 0, n - 1, i, r + 1);
            }
        }
    }
    
    int result = GetValueInTree(1, 0, n - 1, 0, 0);
    
    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}