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
        int a,b,c,m;
        cin >> a >> b >> c >> m;
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        int mn=max(0,v[2]-1-(v[0]+v[1]));
        int mx=a+b+c-3;
        if(mn<=m&&m<=mx) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}