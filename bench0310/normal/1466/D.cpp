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
        vector<ll> w(n+1,0);
        for(int i=1;i<=n;i++) cin >> w[i];
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<ll> x;
        for(int i=1;i<=n;i++) for(int j=0;j<(int)v[i].size()-1;j++) x.push_back(w[i]);
        sort(x.begin(),x.end(),greater<ll>());
        ll res=0;
        for(int i=1;i<=n;i++) res+=w[i];
        int idx=0;
        for(int i=1;i<=n-1;i++)
        {
            cout << res << " \n"[i==n-1];
            if(i<n-1) res+=x[idx++];
        }
    }
    return 0;
}