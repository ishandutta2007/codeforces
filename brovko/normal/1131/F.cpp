#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x, y, p[200005], siz[200005], l[200005], r[200005], ans[200005];

int get(int x)
{
    if(x==p[x])
        return x;
    p[x]=get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x=get(x);
    y=get(y);
    if(siz[x]>siz[y])
        swap(x, y);

    ans[r[x]]=l[y];
    p[x]=y;
    siz[y]+=siz[x];
    l[y]=l[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<=n;i++)
    {
        p[i]=i;
        siz[i]=1;
        l[i]=i;
        r[i]=i;
    }

    for(int i=0;i<n-1;i++)
    {
        cin >> x >> y;
        unite(x, y);
    }

    int a=l[get(1)];
    for(int i=0;i<n;i++)
    {
        cout << a << ' ';
        a=ans[a];
    }
}