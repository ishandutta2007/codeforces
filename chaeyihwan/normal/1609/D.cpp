#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int path[1002], h[1002];

int f(int x)
{
    if(x == path[x]) return x;
    return path[x] = f(path[x]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, d; cin >> n >> d;
    for(int i=1;i<=n;i++)
    {
        path[i] = i;
        h[i] = 1;
    }
    int cnt = 1;
    multiset<int> siz;
    for(int i=1;i<=n;i++) siz.insert(-1);
    for(int i=1;i<=d;i++)
    {
        int x, y; cin >> x >> y;
        x = f(x), y = f(y);
        if(x == y) cnt++;
        else
        {
            path[y] = x;
            siz.erase(siz.find(-h[x]));
            siz.erase(siz.find(-h[y]));
            h[x] += h[y];
            siz.insert(-h[x]);
        }
        int j = 0;
        int ans = 0;
        for(int u : siz)
        {
            j++;
            if(j > cnt) break;
            ans -= u;
        }
        cout << ans - 1 << "\n";
    }
}