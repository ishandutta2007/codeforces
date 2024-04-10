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
        for(int o=0;o<n;o++) cin >> s[o];
        int res=0;
        for(int o=0;o<n-1;o++) res+=(s[o][m-1]!='D');
        for(int i=0;i<m-1;i++) res+=(s[n-1][i]!='R');
        cout << res << "\n";
    }
    return 0;
}