#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    while (a > 0 && b > 0) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}

typedef long long ll;

const int max_n = 1e5 + 100;
const int max_g = 30;

int n;
int a[max_n];
int b[max_n][max_g];
int c[max_n][max_g];
int s[max_n];

pair<int, ll> ans[max_n * max_g];
int ans_s;

ll get_ans(int x)
{
    int l = 0;
    int r = ans_s - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (ans[m].first == x) {
            return ans[m].second;
        } else if (ans[m].first < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return 0;
}

int table[max_n][max_g];

void build_table()
{
    for (int i = n - 1; i >= 0; --i) {
        table[i][0] = a[i];
        for (int j = 1; j < max_g; ++j) {
            if (i + (1 << (j - 1)) < n) {
                table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            } else {
                table[i][j] = table[i][j - 1];
            }
        }
    }
}

int precalc_log[max_n];

void get_precalc_log()
{
    precalc_log[1] = 0;
    int x = 0;
    for (int i = 2; i < max_n; ++i) {
        if ((1 << (x + 1)) <= i) {
            ++x;
        }
        precalc_log[i] = x;
    }
}

int get_gcd(int l, int r)
{
    int len = r - l + 1;
    int pw = precalc_log[len];
    return gcd(table[l][pw], table[r - (1 << pw) + 1][pw]);
}

int main()
{
    /*
    freopen("input.txt",  "w", stdout);
    int n = 1e5;
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int m = 3e5;
    cout << m << endl;
    for (int i = 0; i < m; ++i) {
        cout << i + 1 << endl;
    }
    return 0;
    */
  //  freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    build_table();
    get_precalc_log();

    for (int i = n - 1; i >= 0; --i) {
        int j = i;
        while (j < n) {
            int x = get_gcd(i, j);
            int l = j;
            int r = n - 1;
            int pos = j;
            while (l <= r) {
                int m = (l + r) >> 1;
                
                if (get_gcd(i, m) == x) {
                    pos = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            b[i][s[i]] = x;
            c[i][s[i]] = pos - j + 1;
            ++s[i];
            j = pos + 1;
        }
    }

    ans_s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i]; ++j) {
            ans[ans_s].first = b[i][j];
            ans[ans_s].second = c[i][j];
            ++ans_s;
        }
    }
    
    sort(ans, ans + ans_s);
    
    int old_ans_s = ans_s;
    ans_s = 1;
    for (int i = 1; i < old_ans_s; ++i) {
        if (ans[i].first == ans[ans_s - 1].first) {
            ans[ans_s - 1].second += ans[i].second;
        } else {
            ans[ans_s].first = ans[i].first;
            ans[ans_s].second = ans[i].second;
            ++ans_s;
        }
    }
    
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int x;
        scanf("%d", &x);
        cout << get_ans(x) << endl;
    }
    
    return 0;
}