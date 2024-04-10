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
        int n,x,y;
        cin >> n >> x >> y;
        vector<int> a(n+1,0);
        vector<bool> vis(n+2,0);
        vector<int> id[n+2];
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            vis[a[i]]=1;
            id[a[i]].push_back(i);
        }
        int neutral=0;
        for(int i=1;i<=n+1;i++) if(vis[i]==0) neutral=i;
        priority_queue<array<int,2>> q;
        for(int i=1;i<=n+1;i++) q.push({(int)id[i].size(),i});
        vector<int> res(n+1,0);
        for(int i=0;i<x;i++)
        {
            int val=q.top()[1];
            q.pop();
            int mt=id[val].back();
            id[val].pop_back();
            res[mt]=a[mt];
            q.push({(int)id[val].size(),val});
        }
        int rem=n-x;
        int mx=q.top()[0];
        if((mx>rem-mx&&2*(rem-mx)<y-x)||(mx==rem&&y-x>0))
        {
            cout << "NO\n";
            continue;
        }
        vector<array<int,2>> v;
        for(int i=1;i<=n+1;i++)
        {
            for(int mt:id[i]) v.push_back({i,mt});
        }
        vector<int> nxt(rem);
        for(int i=0;i<rem;i++) nxt[(i+mx)%rem]=v[i][0];
        int now=rem;
        for(int i=0;i<rem;i++)
        {
            if(v[i][0]==nxt[i])
            {
                nxt[i]=neutral;
                now--;
            }
        }
        now-=(y-x);
        for(int i=0;i<rem;i++)
        {
            if(now>0&&nxt[i]!=neutral)
            {
                nxt[i]=neutral;
                now--;
            }
        }
        for(int i=0;i<rem;i++) res[v[i][1]]=nxt[i];
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}