#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

// const char kBadSymbol = 

inline void ModSum(int& x, int y)
{
    x += y;
    if (x >= kMod) {
        x -= kMod;
    }
    if (x < 0) {
        x += kMod;
    }
}

inline int GetModSum(int x, int y)
{
    ModSum(x, y);
    return x;
}

inline int GetBit(int mask, int num)
{
    return (mask >> num) & 1;
}

inline int GetAmountOfBits(int mask)
{
    int r = 0;
    while (mask > 0) {
        r += (mask & 1);
        mask >>= 1;
    }
    return r;
}

const int kMaxN = 1e4;

int n;
char field[3][kMaxN + 1];
int si;
int sj;

vector<int> ti, tj;

char a[3][kMaxN + 1];
int ans[8][kMaxN + 1];

int GetDp()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans[i][j] = 0;
        }
    }
    ans[0][0] = 1;
    for (int j = 0; j < n; ++j) {
        for (int prev_mask = 0; prev_mask < 8; ++prev_mask) {
            bool good = true;
            int next_mask = 7;
            for (int i = 0; i < 3; ++i) {
                if (GetBit(prev_mask, i)) {
                    if (a[i][j] == 'X') {
                        good = false;
                    }
                    next_mask -= (1 << i);
                }
            }
            if (!good) {
                continue;
            }
            for (int i = 0; i < 3; ++i) {
                if (a[i][j] == 'X') {
                    next_mask -= (1 << i);
                }
            }
            ModSum(ans[next_mask][j + 1], ans[prev_mask][j]);
            if (GetBit(next_mask, 0) && GetBit(next_mask, 1)) {
                ModSum(ans[next_mask - (1 << 0) - (1 << 1)][j + 1], ans[prev_mask][j]);
            }
            if (GetBit(next_mask, 1) && GetBit(next_mask, 2)) {
                ModSum(ans[next_mask - (1 << 1) - (1 << 2)][j + 1], ans[prev_mask][j]);
            }
        }
    }
    return ans[0][n];
}

bool ConstructField(int mask)
{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = field[i][j];
        }
    }
    // cout << "IN construction: " << endl;
    a[si][sj] = 'X';
    for (int i = 0; i < 4; ++i) {
        if (GetBit(mask, i)) {
            for (int j = 0; j < 2; ++j) {
                int ci = ti[2 * i + j];
                int cj = tj[2 * i + j];
                
                // cout << "trying ci, cj = " << ci << ", " << cj << endl;
                
                if (!(ci >= 0 && ci < 3 && cj >= 0 && cj < n)) {
                    return false;
                }
                if (field[ci][cj] == 'X') {
                    return false;
                }
                a[ci][cj] = 'X';
            }
        }
    }
    // cout << "After construction: " << endl;
    /*
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    */
    return true;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        cin >> field[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (field[i][j] == 'O') {
                si = i;
                sj = j;
            }
        }
    }
    
    ti.push_back(si - 1);
    tj.push_back(sj);
    ti.push_back(si - 2);
    tj.push_back(sj);
    
    ti.push_back(si + 1);
    tj.push_back(sj);
    ti.push_back(si + 2);
    tj.push_back(sj);
    
    ti.push_back(si);
    tj.push_back(sj - 2);
    ti.push_back(si);
    tj.push_back(sj - 1);
    
    ti.push_back(si);
    tj.push_back(sj + 1);
    ti.push_back(si);
    tj.push_back(sj + 2);
    
    int ans = 0;
    for (int mask = 1; mask < (1 << 4); ++mask) {
        if (!ConstructField(mask)) {
            continue;
        }
        if (GetAmountOfBits(mask) & 1) {
            ModSum(ans, GetDp());
        } else {
            ModSum(ans, -GetDp());
        }
    }
    
    cout << ans << endl;
    
    return 0;
}