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
        vector<int> p(n,0);
        vector<int> pos(n,0);
        for(int i=0;i<n;i++)
        {
            cin >> p[i];
            p[i]--;
            pos[p[i]]=i;
        }
        vector<int> x(n,0);
        for(int i=0;i<n;i++) x[(pos[i]-i+n)%n]++;
        auto ch=[&](int k)->bool
        {
            vector<int> q(n,0);
            for(int i=0;i<n;i++) q[i]=(i-k+n)%n;
            vector<int> h(n,0);
            for(int i=0;i<n;i++) h[q[i]]=i;
            vector<int> tmp(n);
            for(int i=0;i<n;i++) tmp[i]=h[p[i]];
            int c=0;
            vector<bool> vis(n,0);
            for(int i=0;i<n;i++)
            {
                if(vis[i]) continue;
                c++;
                int a=i;
                while(vis[a]==0)
                {
                    vis[a]=1;
                    a=tmp[a];
                }
            }
            return (n-c<=m);
        };
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int mn=(n-x[i]+1)/2;
            if(m<mn) continue;
            if(ch(i)) res.push_back(i);
        }
        cout << res.size() << "\n";
        for(int k:res) cout << k << " ";
        cout << "\n";
    }
    return 0;
}