#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 1e5;
const int kMaxLog = 20;

int n, m, k;
vector<vector<int> > a;
vector<vector<vector<int> > > table;
vector<int> prelog;

int GetFromTable(int l, int r, int j)
{
    int len = r - l + 1;
    int len_log = prelog[len];
    return max(table[l][j][len_log], table[r - (1 << len_log) + 1][j][len_log]);
}

bool Check(int l, int r, vector<int>& ans)
{
    int need_k = 0;
    for (int i = 0; i < m; ++i) {
        need_k += GetFromTable(l, r, i);
    }
    if (need_k <= k) {
        for (int i = 0; i < m; ++i) {
            ans[i] = GetFromTable(l, r, i);
        }
        return true;
    } else {
        return false;
    }
}

bool Check(int len, vector<int>& ans)
{
    for (int i = 0; i + len - 1 < n; ++i) {
        if (Check(i, i + len - 1, ans)) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    a.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    prelog.resize(kMaxN + 1);
    prelog[1] = 0;
    for (int i = 2; i <= kMaxN; ++i) {
        prelog[i] = prelog[i - 1];
        if ((1 << (prelog[i] + 1)) <= i) {
            ++prelog[i];
        }
    }

    table.resize(n, vector<vector<int> >(m, vector<int>(kMaxLog)));
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            table[i][j][0] = a[i][j];
        }
        for (int k = 1; k < kMaxLog; ++k) {
            for (int i = 0; i < n; ++i) {
                table[i][j][k] = table[i][j][k - 1];
                if (i + (1 << (k - 1)) < n) {
                    table[i][j][k] = max(table[i][j][k], table[i + (1 << (k - 1))][j][k - 1]);
                }
            }
        }
    }

    vector<int> ans(m, 0);
    int ans_amount = 0;

    int bl = 1, br = n;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        if (Check(bm, ans)) {
            ans_amount = bm;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;
}