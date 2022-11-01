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
        vector<vector<int>> res(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n-1;i++) res[i][i]=res[i+1][i]=1;
        res[n][n]=res[1][n]=1;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cout << res[i][j] << " \n"[j==n];
    }
    return 0;
}