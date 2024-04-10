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
        ll w,h,n;
        cin >> w >> h >> n;
        ll a=1;
        while((w%2)==0)
        {
            a*=2;
            w/=2;
        }
        ll b=1;
        while((h%2)==0)
        {
            b*=2;
            h/=2;
        }
        if(a*b>=n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}