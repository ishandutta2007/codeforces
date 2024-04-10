#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> a >> b >> c;
    if(a>b)
        swap(a, b);
    if(b>c)
        swap(b, c);
    if(a>b)
        swap(a, b);

    if(a==b && b==c)
    {
        cout << 0;
        return 0;
    }

    if(a[1] == b[1] && a[1]==c[1] && a[0]==b[0]-1 && b[0]==c[0]-1)
    {
        cout << 0;
        return 0;
    }

    if(a==b || b==c)
    {
        cout << 1;
        return 0;
    }

    if(a[0]==b[0]-1 && a[1]==b[1])
    {
        cout << 1;
        return 0;
    }

    if(a[0]==c[0]-1 && a[1]==c[1])
    {
        cout << 1;
        return 0;
    }

    if(b[0]==c[0]-1 && b[1]==c[1])
    {
        cout << 1;
        return 0;
    }

    if(a[0]==b[0]-2 && a[1]==b[1])
    {
        cout << 1;
        return 0;
    }

    if(a[0]==c[0]-2 && a[1]==c[1])
    {
        cout << 1;
        return 0;
    }

    if(b[0]==c[0]-2 && b[1]==c[1])
    {
        cout << 1;
        return 0;
    }

    cout << 2;
}