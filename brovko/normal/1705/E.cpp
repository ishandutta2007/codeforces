#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

using namespace std;
const int N = 2e5 + 113;

int t[N], add[N];

int sum(int r)
{
    int ans = 0;

    for(int i = r; i >= 0; i = (i & i + 1) - 1)
        ans += t[i] + add[i] * (i - (i & i + 1) + 1);

    for(int i = (r | r + 1); i < N; i = (i | i + 1))
        ans += add[i] * (r - (i & i + 1) + 1);

    return ans;
}

void inc(int r, int d)
{
    for(int i = r; i >= 0; i = (i & i + 1) - 1)
        add[i] += d;

    for(int i = (r | r + 1); i < N; i = (i | i + 1))
        t[i] += d * (r - (i & i + 1) + 1);
}

void inc(int l, int r, int d)
{
    inc(r, d);

    if(l > 0)
        inc(l - 1, -d);
}

int sum(int l, int r)
{
    return sum(r) - (l == 0 ? 0 : sum(l - 1));
}

void Add(int x)
{
    int L = x - 1, R = N;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(sum(x, M) == M - x + 1)
            L = M;
        else R = M;
    }

    inc(x, L, -1);
    inc(R, R, 1);
}

void Sub(int x)
{
    int L = x - 1, R = N;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(sum(x, M) == 0)
            L = M;
        else R = M;
    }

    inc(x, L, 1);
    inc(R, R, -1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        Add(a[i]);
    }

    while(q--)
    {
        int i, x;
        cin >> i >> x;

        i--;

        Sub(a[i]);
        a[i] = x;
        Add(x);

        int L = 0, R = N;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(sum(M, R) == 0)
                R = M;
            else L = M;
        }

        cout << L << "\n";
    }
}