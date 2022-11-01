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
        ll h;
        cin >> n >> h;
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(),v.end(),greater<>());
        ll a=v[0],b=v[1];
        ll s=(h+a+b-1)/(a+b);
        cout << 2*s-((s-1)*(a+b)+a>=h) << "\n";
    }
    return 0;
}