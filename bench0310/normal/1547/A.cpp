#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        array<int,2> a,b,f;
        cin >> a[0] >> a[1] >> b[0] >> b[1] >> f[0] >> f[1];
        auto d=[&](array<int,2> x,array<int,2> y)->int{return abs(x[0]-y[0])+abs(x[1]-y[1]);};
        if(a[0]!=b[0]&&a[1]!=b[1]) cout << d(a,b) << "\n";
        else if(d(a,b)<d(a,f)+d(f,b)) cout << d(a,b) << "\n";
        else cout << d(a,b)+2 << "\n";
    }
    return 0;
}