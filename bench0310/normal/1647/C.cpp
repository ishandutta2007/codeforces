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
        for(int i=0;i<n;i++) cin >> s[i];
        vector<array<int,4>> res;
        for(int j=m-1;j>=1;j--)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i][j]=='1') res.push_back({i,j-1,i,j});
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            if(s[i][0]=='1') res.push_back({i-1,0,i,0});
        }
        if(s[0][0]=='0')
        {
            cout << res.size() << "\n";
            for(auto [a,b,c,d]:res) cout << a+1 << " " << b+1 << " " << c+1 << " " << d+1 << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}