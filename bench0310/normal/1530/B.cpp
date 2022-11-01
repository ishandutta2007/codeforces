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
        vector<string> res(n,string(m,'0'));
        for(int i=0;i<n;i+=(n-1)) for(int j=0;j<m;j+=(m-1)) res[i][j]='1';
        for(int j=2;j+2<=m-1;j+=2) res[0][j]=res[n-1][j]='1';
        for(int i=2;i+2<=n-1;i+=2) res[i][0]=res[i][m-1]='1';
        for(int i=0;i<n;i++) cout << res[i] << "\n";
        cout << "\n";
    }
    return 0;
}