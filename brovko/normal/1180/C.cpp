#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[500005], q, b[100005], c[100005], d[100005], e[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> q;
    int Max=0;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            Max=max(Max, a[i]);
        }

    int x=1;
    int y=0;
    while(a[y]!=Max)
    {
        b[x]=a[y];
        c[x]=a[y+1];
        a[y+n]=min(a[y], a[y+1]);
        a[y+1]=max(a[y], a[y+1]);
        y++;
        x++;
    }

    int z=x;

    for(int i=0;i<n;i++)
    {
        d[x%(n-1)]=a[y];
        e[x%(n-1)]=a[y+1];
        a[y+n]=min(a[y], a[y+1]);
        a[y+1]=max(a[y], a[y+1]);
        y++;
        x++;
    }

    while(q--)
    {
        int p;
        cin >> p;
        if(p<z)
            cout << b[p] << ' ' << c[p] << endl;
        else cout << d[p%(n-1)] << ' ' << e[p%(n-1)] << endl;
    }
}