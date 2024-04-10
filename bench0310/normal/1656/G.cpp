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
        vector<int> e(n+1,0);
        vector<int> c(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> e[i];
            c[e[i]]++;
        }
        int odd=0;
        bool bad=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]&1)
            {
                bad|=(odd!=0);
                odd=i;
            }
        }
        vector<array<int,2>> v;
        bool one=0;
        vector<int> q(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if((c[e[i]]&1)&&i!=(n+1)/2&&!one)
            {
                q[(n+1)/2]=i;
                one=1;
            }
            else v.push_back({e[i],i});
        }
        bad|=((n&1)&&!one);
        if(bad)
        {
            cout << "NO\n";
            continue;
        }
        ranges::sort(v);
        int idx=0;
        for(int i=1;i<=n/2;i++)
        {
            q[i]=v[idx++][1];
            q[n+1-i]=v[idx++][1];
        }
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        function<int(int)> find_set=[&](int a)->int
        {
            if(p[a]==a) return a;
            else return p[a]=find_set(p[a]);
        };
        auto merge_sets=[&](int a,int b)->bool
        {
            a=find_set(a);
            b=find_set(b);
            if(a==b) return 0;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
            return 1;
        };
        vector<bool> vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            int a=i;
            while(!vis[a])
            {
                vis[a]=1;
                merge_sets(a,q[a]);
                a=q[a];
            }
        }
        for(int i=1;i<=n/2;i++)
        {
            if(merge_sets(i,n+1-i)) swap(q[i],q[n+1-i]);
        }
        for(int i=2;i<=n/2;i++)
        {
            if(merge_sets(1,i))
            {
                swap(q[1],q[i]);
                swap(q[1],q[n]);
                swap(q[1],q[n+1-i]);
            }
        }
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << q[i] << " \n"[i==n];
    }
    return 0;
}