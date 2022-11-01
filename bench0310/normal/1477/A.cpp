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
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> x(n);
        for(int i=0;i<n;i++) cin >> x[i];
        sort(x.begin(),x.end());
        ll g=(x[1]-x[0]);
        for(int i=0;i<n-1;i++) g=gcd(g,x[i+1]-x[i]);
        auto m=[&](ll a,ll b)->ll{return ((a%b)+b)%b;};
        if(g==1||m(k,g)==m(x[0],g)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}