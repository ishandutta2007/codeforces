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
        int m;
        cin >> m;
        vector<int> b(m+1,0);
        for(int i=1;i<=m;i++) cin >> b[i];
        vector<int> one(n+1,0);
        for(int i=1;i<=n;i++) one[i]=one[i-1]+a[i];
        vector<int> two(m+1,0);
        for(int i=1;i<=m;i++) two[i]=two[i-1]+b[i];
        int res=0;
        for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) res=max(res,one[i]+two[j]);
        cout << res << "\n";
    }
    return 0;
}