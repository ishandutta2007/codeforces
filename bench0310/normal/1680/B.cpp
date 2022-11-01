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
        vector<string> s(n);
        array<int,3> p={n+m,0,0};
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            for(int j=0;j<m;j++) if(s[i][j]=='R') p=min(p,{i+j,i,j});
        }
        bool ok=1;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) ok&=(s[i][j]=='E'||(i>=p[1]&&j>=p[2]));
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}