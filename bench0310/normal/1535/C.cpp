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
        string s;
        cin >> s;
        vector<int> v[2][2]; //tp,id
        int n=s.size();
        s="$"+s;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0'||s[i]=='1') v[s[i]-'0'][i&1].push_back(i);
        }
        ll res=0;
        vector<array<int,2>> idx(2,{0,0});
        vector<array<int,2>> sz(2,{0,0});
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) sz[i][j]=(v[i][j].size());
        for(int i=1;i<=n;i++)
        {
            int bad=n+1;
            for(int j=0;j<2;j++)
            {
                if(idx[j][0]<sz[j][0]&&idx[j][1]<sz[j][1]) bad=min(bad,max(v[j][0][idx[j][0]],v[j][1][idx[j][1]]));
                for(int x=0;x<2;x++) if(idx[j][x]<sz[j][x]&&idx[j^1][x]<sz[j^1][x]) bad=min(bad,max(v[j][x][idx[j][x]],v[j^1][x][idx[j^1][x]]));
            }
            res+=(bad-i);
            if(s[i]=='0'||s[i]=='1') idx[s[i]-'0'][i&1]++;
        }
        cout << res << "\n";
    }
    return 0;
}