#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    ll l=0,r=(1ll<<60);
    while(l<r-1)
    {
        ll m=(l+r)/2;
        ll c=(m-1)/2+max(ll(0),m-4)/4;
        if(c>=n) r=m;
        else l=m;
    }
    cout << r << "\n";
    return 0;
}