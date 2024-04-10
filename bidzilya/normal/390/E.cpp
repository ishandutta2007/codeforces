#include <bits/stdc++.h>
using namespace std;

struct FenwickTree
{
    void Init(int _n)
    {
        n = _n;
        a.assign(n, 0);
    }
    
    long long Get(int pos) const
    {
        long long r = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            r += a[pos];
        }
        return r;
    }
    
    void Inc(int pos, long long val)
    {
        for (; pos < n; pos |= (pos + 1)) {
            a[pos] += val;
        }
    }
    
    long long Get(int l, int r) const
    {
        if (l == 0) {
            return Get(r);
        }
        return Get(r) - Get(l - 1);
    }
    
    int n;
    vector<long long> a;
};

struct RangeFenwickTree
{
    void Init(int _n)
    {
        n = _n;
        add.Init(_n);
        mult.Init(_n);
    }
    
    long long Get(int pos) const
    {
        long long ca = add.Get(pos);
        long long cm = mult.Get(pos);
        return cm * pos + ca;
    }
    
    long long Get(int l, int r) const
    {
        if (l == 0) {
            return Get(r);
        }
        return Get(r) - Get(l - 1);
    }
    
    void Inc(int l, int r, long long val)
    {
        add.Inc(l, -val * (l - 1));
        mult.Inc(l, val);
        if (r + 1 < n) {
            mult.Inc(r + 1, -val);
            add.Inc(r + 1, val * r);
        }
    }
    
    int n;
    FenwickTree add, mult;
};

void TestRangeFenwickTree()
{
    int n;
    cin >> n;
    vector<long long> a(n, 0);
    RangeFenwickTree fw;
    fw.Init(n);
    for (int itr = 0; itr < 100; ++itr) {
        int l = rand() % n;
        int r = rand() % n;
        if (l > r) {
            swap(l, r);
        }
        long long val = rand();
        fw.Inc(l, r, val);
        for (int i = l; i <= r; ++i) {
            a[i] += val;
        }
        for (int i = 0; i < n; ++i) {
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum += a[j];
                assert(fw.Get(i, j) == sum);
            }
        }
    }
    
}

int main()
{
    // TestRangeFenwickTree();
    
    // freopen("input.txt", "r", stdin);
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n, m, w;
    cin >> n >> m >> w;
    RangeFenwickTree sx, sy;
    sx.Init(n);
    sy.Init(m);
    while (w > 0) {
        int tp;
        int x1, y1, x2, y2;
        cin >> tp >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        --x2;
        --y2;
        if (tp == 0) { 
            long long val;
            cin >> val;
            sx.Inc(x1, x2, val * (y2 - y1 + 1));
            sy.Inc(y1, y2, val * (x2 - x1 + 1));
        } else {
            long long res = sx.Get(x1, x2) + sy.Get(y1, y2);
            res -= sx.Get(0, x1 - 1);
            res -= sx.Get(x2 + 1, n - 1);
            res -= sy.Get(0, y1 - 1);
            res -= sy.Get(y2 + 1, m - 1);
            cout << res / 2 << '\n';
        }
        --w;
    }
    cout.flush();
   
    return 0;
}