#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<string> s(n);
        for(int i=0;i<n;i++) cin >> s[i];
        vector<string> t(n,string(m,'.'));
        for(int j=0;j<m;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                if(s[i][j]=='o') t[i][j]='o';
                if(s[i][j]=='*')
                {
                    int r=i;
                    while(r+1<n&&t[r+1][j]=='.') r++;
                    t[r][j]='*';
                }
            }
        }
        for(int i=0;i<n;i++) cout << t[i] << "\n";
    }
    return 0;
}