#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, p[200005], siz[200005];

int get(int x)
{
    if(p[x]==x)
        return x;
    p[x]=get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x=get(x);
    y=get(y);
    if(x>y)
        swap(x, y);
    p[x]=y;
    siz[y]+=siz[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        siz[i]=1;
    }
    for(int i=0;i<m;i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            unite(u, v);
        }
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        if(get(i)>get(i+1))
        {
            ans++;
            unite(i, i+1);
        }
    }
    cout << ans;
}