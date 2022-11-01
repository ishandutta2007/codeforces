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
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int res=0;
        for(int i=1;i<=m;i++)
        {
            int b;
            cin >> b;
            for(int j=1;j<=n;j++) if(a[j]==b) res=b;
        }
        if(res!=0) 
        {
            cout << "YES\n";
            cout << "1 " << res << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}