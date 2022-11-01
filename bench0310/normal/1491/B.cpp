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
        ll u,v;
        cin >> n >> u >> v;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int mx=0;
        for(int i=1;i<n;i++) mx=max(mx,abs(a[i]-a[i+1]));
        if(mx==0) cout << v+min(u,v) << "\n";
        else if(mx==1) cout << min(u,v) << "\n";
        else cout << "0\n";
    }
    return 0;
}