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
        vector<vector<int>> a(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> a[i][j];
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            int r=i,c=1;
            int x=0;
            while(r>=1&&c<=m) x^=a[r--][c++];
            ok&=(x==0);
        }
        for(int j=2;j<=m;j++)
        {
            int r=n,c=j;
            int x=0;
            while(r>=1&&c<=m) x^=a[r--][c++];
            ok&=(x==0);
        }
        if(ok==0) cout << "Ashish\n";
        else cout << "Jeel\n";
    }
    return 0;
}