#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, x1[200005], y1[200005], x2[200005], y2[200005], X1[200005], Y1[200005];

int g(int x, int y)
{
    int k=0;

    for(int i=0;i<n;i++)
        if(x1[i]<=x && x2[i]>=x && y1[i]<=y && y2[i]>=y)
            k++;
    if(k>=n-1)
        return 1;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

    int Maxx=0, Minx=1e9, Maxy=0, Miny=1e9;

    for(int i=0; i<n; i++)
    {
        X1[i]=x1[i];
        Y1[i]=y1[i];
    }

    sort(X1, X1+n);
    sort(Y1, Y1+n);

    if(g(X1[n-1], Y1[n-1]))
        cout << X1[n-1] << ' ' << Y1[n-1];
    else if(g(X1[n-2], Y1[n-1]))
        cout << X1[n-2] << ' ' << Y1[n-1];
    else if(g(X1[n-1], Y1[n-2]))
        cout << X1[n-1] << ' ' << Y1[n-2];
    else if(g(X1[n-2], Y1[n-2]))
        cout << X1[n-2] << ' ' << Y1[n-2];
    else while(true);

}