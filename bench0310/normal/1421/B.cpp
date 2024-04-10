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
        vector<string> s(n+1);
        for(int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]="$"+s[i];
        }
        vector<array<int,2>> res;
        if(s[1][2]==s[2][1])
        {
            char c=s[1][2];
            if(s[n-1][n]==c) res.push_back({n-1,n});
            if(s[n][n-1]==c) res.push_back({n,n-1});
        }
        else if(s[n-1][n]==s[n][n-1])
        {
            char c=s[n-1][n];
            if(s[1][2]==c) res.push_back({1,2});
            if(s[2][1]==c) res.push_back({2,1});
        }
        else
        {
            res.push_back({1,2});
            char c=s[2][1];
            if(s[n-1][n]==c) res.push_back({n-1,n});
            if(s[n][n-1]==c) res.push_back({n,n-1});
        }
        cout << res.size() << "\n";
        for(auto [a,b]:res) cout << a << " " << b << "\n";
    }
    return 0;
}