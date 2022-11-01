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
        int n,x;
        cin >> n >> x;
        vector<int> d(n+1,0);
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            d[a]++; d[b]++;
        }
        vector<int> p(n+1,0);
        vector<int> pos(n+1,0);
        vector<int> bad;
        for(int i=1;i<=n;i++)
        {
            cin >> p[i];
            pos[p[i]]=i;
            if(p[i]!=i) bad.push_back(p[i]);
        }
        int c=0;
        vector<bool> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int a=i;
            int sz=0;
            while(!vis[a])
            {
                vis[a]=1;
                a=p[a];
                sz++;
            }
            c=(c+sz-1)&1;
        }
        int m=0;
        for(int i=1;i<=n;i++) if(d[i]==n-1) m=i;
        bool alice=[&]()->bool
        {
            if(m==0) return 1;
            bool ok=1;
            for(int i=1;i<=n;i++) ok&=(p[i]==i);
            if(ok) return 1;
            if(bad.size()==2)
            {
                if(x!=bad[0]&&x!=bad[1]) return 1;
            }
            if(pos[m]!=m&&(x==m||x==p[m])) return 0;
            return (c==(x==m));
        }();
        if(alice) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}