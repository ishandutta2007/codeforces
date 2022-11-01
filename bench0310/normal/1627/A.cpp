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
        int n,m,r,c;
        cin >> n >> m >> r >> c;
        r--; c--;
        vector<int> row(n,0);
        vector<int> col(m,0);
        vector<string> s(n);
        int b=0;
        for(int i=0;i<n;i++)
        {
            cin >> s[i];
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='B')
                {
                    row[i]=1;
                    col[j]=1;
                    b=1;
                }
            }
        }
        int res=-1;
        if(s[r][c]=='B') res=0;
        else if(row[r]||col[c]) res=1;
        else if(b) res=2;
        cout << res << "\n";
    }
    return 0;
}