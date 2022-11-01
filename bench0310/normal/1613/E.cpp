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
        vector<string> s(n+2);
        s[0]=s[n+1]=string(m+1,'#');
        array<int,2> src={0,0};
        for(int i=1;i<=n;i++)
        {
            cin >> s[i];
            s[i]="#"+s[i]+"#";
            for(int j=1;j<=m;j++) if(s[i][j]=='L') src={i,j};
        }
        queue<array<int,2>> q;
        vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
        auto add=[&](int r,int c)
        {
            s[r][c]='+';
            for(auto [dr,dc]:z) if(s[r+dr][c+dc]=='.') q.push({r+dr,c+dc});
        };
        add(src[0],src[1]);
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            int cnt=0;
            for(auto [dr,dc]:z) cnt+=(s[r+dr][c+dc]=='.');
            if(cnt<=1) add(r,c);
        }
        s[src[0]][src[1]]='L';
        for(int i=1;i<=n;i++) cout << s[i].substr(1,m) << "\n";
    }
    return 0;
}