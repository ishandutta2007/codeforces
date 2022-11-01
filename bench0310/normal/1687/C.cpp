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
        vector<ll> s(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            s[i]+=a;
        }
        for(int i=1;i<=n;i++)
        {
            int b;
            cin >> b;
            s[i]-=b;
        }
        for(int i=1;i<=n;i++) s[i]+=s[i-1];
        set<int> p;
        for(int i=0;i<=n;i++) p.insert(i);
        vector<int> v[n+1];
        for(int i=1;i<=m;i++)
        {
            int l,r;
            cin >> l >> r;
            v[l-1].push_back(r);
            v[r].push_back(l-1);
        }
        queue<int> q;
        auto rm=[&](int l,int r)
        {
            if(l>r) swap(l,r);
            l++;
            while(1)
            {
                auto it=p.lower_bound(l);
                if(it!=p.end()&&(*it)<=r)
                {
                    q.push(*it);
                    p.erase(it);
                }
                else break;
            }
        };
        for(int i=0;i<=n;i++) if(s[i]==0) rm(i-1,i);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            s[a]=0;
            for(int b:v[a]) if(s[b]==0) rm(a,b);
        }
        bool ok=1;
        for(int i=0;i<=n;i++) ok&=(s[i]==0);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}