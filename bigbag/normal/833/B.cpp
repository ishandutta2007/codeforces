#include <bits/stdc++.h>

using namespace std;

const int maxn = 101111, max_k = 55, LV = 16;

int n, k, root[maxn], L[LV * maxn], R[LV * maxn], sum[LV * maxn], dp[max_k][maxn], a[maxn];
int C, was[37777];
int rt = 1, sz = 1;
int lpos[maxn];

int copy(int v, int &u)
{
    L[sz] = L[v];
    R[sz] = R[v];
    sum[sz] = sum[v];
    return u = sz++;
}

void make_root()
{
    copy(root[rt - 1], root[rt]);
    rt++;
}

void add(int pos, int x, int v = root[rt - 1], int l = 0, int r = maxn)
{
	sum[v] += x;
    if(r - l == 1)
        return;
    int m = (l + r) / 2;
    if(pos < m)
        add(pos, x, copy(L[v], L[v]), l, m);
    else
        add(pos, x, copy(R[v], R[v]), m, r);
}

int get(int a, int b, int v, int l = 0, int r = maxn)
{
    if(a <= l && r <= b)
        return sum[v];
    if(r <= a || b <= l)
        return 0;
    int m = (l + r) / 2;
    return get(a, b, L[v], l, m) + get(a, b, R[v], m, r);
}

void prec() {
    set<int> q;
    for (int i = 1; i <= n; ++i) {
        q.insert(a[i]);
        dp[1][i] = q.size();
    }
}

inline int get_diff(int l, int r) {
    return get(l, r + 1, root[r]);
}

void get_dp(int k, int l, int r, int cl, int cr) {
    int mid = (l + r) / 2;
    int pos = mid;
    if (mid <= cr) {
        ++C;
        int diff = 0;
        for (int i = mid; i >= cl; --i) {
            if (was[a[i]] < C) {
                was[a[i]] = C;
                ++diff;
            }
            int res = dp[k - 1][i - 1] + diff;
            if (dp[k][mid] < res) {
                dp[k][mid] = res;
                pos = i;
            }
        }
    } else {
        for (int i = cl; i <= mid && i <= cr; ++i) {
            int res = dp[k - 1][i - 1] + get_diff(i, mid);
            if (dp[k][mid] < res) {
                dp[k][mid] = res;
                pos = i;
            }
        }
    }
    if (l < mid) {
        get_dp(k, l, mid - 1, cl, min(cr, pos));
    }
    if (mid < r) {
        get_dp(k, mid + 1, r, max(cl, pos), cr);
    }
}

int main()
 {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        a[i] = t;
        make_root();
        add(lpos[t], -1);
        lpos[t] = i;
        add(lpos[t], 1);
    }
    prec();
    for (int i = 2; i <= k; ++i) {
        get_dp(i, 1, n, 1, n);
    }
    //cout << get_diff(3, n) << endl;
    printf("%d\n", dp[k][n]);
    return 0;
 }