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
        vector<int> v[n+1];
        for(int i=1;i<=n;i++) v[i].push_back(0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            v[a].push_back(i);
        }
        for(int i=1;i<=n;i++) v[i].push_back(n+1);
        int res=n;
        for(int i=1;i<=n;i++)
        {
            if(v[i].size()==2) continue;
            int c=0;
            for(int j=0;j<(int)v[i].size()-1;j++) c+=(v[i][j]+1<v[i][j+1]);
            res=min(res,c);
        }
        cout << res << "\n";
    }
    return 0;
}