#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 4e5, lgN = log2(maxN);

int a[maxN+5], b[maxN+5], aMax[maxN+5][lgN], bMin[maxN+5][lgN], lg2[maxN+5], p2[lgN];

void pre()
{
    p2[0] = 1;

    for (int i = 1; i <= lgN; ++i)
        p2[i] = 2 * p2[i-1];

    for (int i = 1; i <= maxN; ++i)
        lg2[i] = log2(i);
}

int myMax(int x, int y)
{
    return max(x, y);
}

int myMin(int x, int y)
{
    return min(x, y);
}

void buildSparseTable(int *a, int table[][lgN], int n, int (*f)(int, int))
{
    if (p2[0] != 1)
        pre();

    int maxJ = log2(n);

    for (int j = 0; j <= maxJ; ++j)
    {
        for (int i = 0; i + p2[j] <= n; ++i)
        {
            if (!j)
                table[i][j] = a[i];

            else
                table[i][j] = f(table[i][j-1], table[i+p2[j-1]][j-1]);
        }
    }
}

int querySparseTable(int table[][lgN], int l, int r, int (*f)(int, int))
{
    int ans = table[l][0];

    while (l <= r)
    {
        int k = lg2[r-l+1];

        ans = f(ans, table[l][k]);
        l += p2[k];
    }

    return ans;
}

int bSearchLast(int mx[][lgN], int mn[][lgN], int l, int r, int st)
{
    if (querySparseTable(mx, st, r, myMax) < querySparseTable(mn, st, r, myMin))
        return r;

    if (querySparseTable(mx, st, l, myMax) >= querySparseTable(mn, st, l, myMin))
        return l-1;

    int mid = (l+r)/2;
    int mxAns = querySparseTable(mx, st, mid, myMax);
    int mnAns = querySparseTable(mn, st, mid, myMin);

    if (mxAns < mnAns)
        return bSearchLast(mx, mn, mid+1, r, st);

    return bSearchLast(mx, mn, l, mid-1, st);

}

int bSearchFirst(int mx[][lgN], int mn[][lgN], int l, int r, int st)
{
    if (querySparseTable(mx, st, l, myMax) > querySparseTable(mn, st, l, myMin))
        return l;

    if (querySparseTable(mx, st, r, myMax) <= querySparseTable(mn, st, r, myMin))
        return r+1;

    int mid = (l+r)/2;
    int mxAns = querySparseTable(mx, st, mid, myMax);
    int mnAns = querySparseTable(mn, st, mid, myMin);

    if (mxAns > mnAns)
        return bSearchFirst(mx, mn, l, mid-1, st);

    return bSearchFirst(mx, mn, mid+1, r, st);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    buildSparseTable(a, aMax, n, myMax);
    buildSparseTable(b, bMin, n, myMin);

    long long ans = 0;
    int l, r;

    for (int i = 0; i < n; ++i)
    {
        l = bSearchLast(aMax, bMin, i, n-1, i);
        r = bSearchFirst(aMax, bMin, i, n-1, i);

        if (r > l)
            ans += (r-l-1);
    }

    cout << ans;

    return 0;
}