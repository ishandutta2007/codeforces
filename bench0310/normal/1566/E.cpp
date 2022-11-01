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
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> ch(n+1,0);
        for(int i=2;i<=n;i++) ch[i]=((int)v[i].size()-1);
        vector<int> ch_leaves(n+1,0);
        vector<bool> bad(n+1,0);
        vector<bool> leaf(n+1,0);
        vector<int> buds;
        int leaves=0;
        function<void(int,int)> dfs=[&](int a,int p)
        {
            for(int to:v[a])
            {
                if(to==p) continue;
                dfs(to,a);
                if(bad[to]) bad[a]=1;
                else if(leaf[to]) ch_leaves[a]++;
            }
            if(a!=1&&!bad[a])
            {
                if(ch_leaves[a]>0) buds.push_back(ch_leaves[a]);
                else leaf[a]=1;
            }
            else leaves+=ch_leaves[a];
        };
        dfs(1,0);
        int sum=0;
        for(int b:buds) sum+=b;
        int cnt=buds.size();
        int res=(sum+leaves-cnt);
        if(leaves==0) res++;
        cout << res << "\n";
    }
    return 0;
}