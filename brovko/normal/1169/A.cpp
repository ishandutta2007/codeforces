#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a, x, b, y;

int inc(int x)
{
    if(x==n)
        return 1;
    return x+1;
}

int rec(int x)
{
    if(x==1)
        return n;
    return x-1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> a >> x >> b >> y;
    int f=0;
    if(a==b)
        f=1;
    while(a!=x && b!=y)
    {
        a=inc(a);
        b=rec(b);
        if(a==b)
            f=1;
    }
    if(f)
        cout << "YES";
    else cout << "NO";
}