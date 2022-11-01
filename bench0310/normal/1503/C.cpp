#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,2>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][0] >> v[i][1];
    sort(v.begin(),v.end());
    ll res=0;
    ll m=0;
    for(int i=0;i<n;i++)
    {
        res+=v[i][1];
        if(i>0) res+=max(0ll,v[i][0]-m);
        m=max(m,v[i][0]+v[i][1]);
    }
    cout << res << "\n";
    return 0;
}