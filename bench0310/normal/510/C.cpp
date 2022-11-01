#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    bool ok=1;
    vector<int> g[26];
    vector<int> in(26,0);
    for(int o=0;o<n;o++)
    {
        for(int i=o+1;i<n;i++)
        {
            for(int j=0;j<(int)min(v[o].size(),v[i].size());j++)
            {
                if(v[o][j]!=v[i][j])
                {
                    g[v[o][j]-'a'].push_back(v[i][j]-'a');
                    in[v[i][j]-'a']++;
                    break;
                }
            }
            if(v[o].size()>v[i].size()&&v[o].substr(0,v[i].size())==v[i]) ok=0;
        }
    }
    string res;
    queue<int> q;
    for(int i=0;i<26;i++) if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        res+=(x+'a');
        for(int to:g[x])
        {
            in[to]--;
            if(in[to]==0) q.push(to);
        }
    }
    if(ok&&res.size()==26) cout << res << "\n";
    else cout << "Impossible\n";
    return 0;
}