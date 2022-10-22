#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[6];

int f(int a, int b, int c, int d, int e, int f)
{
    return a*32+b*16+c*8+d*4+e*2+f;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<6;i++)
    {
        a[i]=n%2;
        n/=2;
    }
    for(int i=0;i<3;i++)
        swap(a[i], a[5-i]);
    cout << f(a[0], a[5], a[3], a[2], a[4], a[1]);
}