#include <bits/stdc++.h>
using namespace std;
struct Linear_base {
    int L, bas[32];
    void clear()
    {
        L = 0;
        memset(bas, 0, sizeof(bas));
    }
    void insert(int x)
    {
        for(int i = 1; i <= L; ++i)
        {
            x = min(x, x ^ bas[i]);
        }
        if(!x) return;
        bas[++L] = x;
        for(int i = L; i > 1; --i)
        {
            if(bas[i] > bas[i - 1])
                swap(bas[i], bas[i - 1]);
        }
    }
    void operator += (const Linear_base &y)
    {
        for(int i = 1; i <= y.L; ++i)
            insert(y.bas[i]);
    }
    int max_element()
    {
        int x = 0;
        for(int i = 1; i <= L; ++i)
        {
            x = max(x, x ^ bas[i]);
        }
        return x;
    }
};
int main()
{
#ifdef local
    freopen("test.in", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 0; i < n; ++i)
    {
        int a1, a2;
        cin >> a1 >> a2;
        a[i]=a1 * 60 + a2;
    }
    int ans = 0;
    a[n] = 1000000;
    if(a[0] >= m+1)
        ans = 0;
    else
        for (int i = 0; i < n; ++i)
            if(a[i+1]-a[i]>=m*2+2)
            {
                ans=a[i]+m+1;
                break;
            }
    cout << ans / 60 << ' ' << ans % 60 << endl;
    return 0;
}