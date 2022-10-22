#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, a, b, c, d, x, y, xl, xr, yl, yr;

bool f(int x, int y)
{
    return (x>=xl && x<=xr && y>=yl && y<=yr);
}

int32_t main()
{
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c >> d >> x >> y >> xl >> yl >> xr >> yr;
        int F=1;
        if(xl==xr && a*b!=0)
            F=0;
        if(yl==yr && c*d!=0)
            F=0;
        if(!f(x-a+b, y-c+d))
            F=0;
        if(F==0)
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}