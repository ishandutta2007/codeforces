#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    while(k--)
    {
        ll n,x,t;
        cin >> n >> x >> t;
        ll c=t/x;
        if(n<=c) cout << n*(n-1)/2 << "\n";
        else cout << c*(c-1)/2+(n-c)*c << "\n";
    }
    return 0;
}