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
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> v[2];
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            v[a[i]].push_back(b);
            res+=b;
        }
        for(int i=0;i<2;i++) ranges::sort(v[i],greater<>());
        int m=min(v[0].size(),v[1].size());
        for(int i=0;i<m;i++) res+=(v[0][i]+v[1][i]);
        if(2*m==n) res-=min(v[0][m-1],v[1][m-1]);
        cout << res << "\n";
    }
    return 0;
}