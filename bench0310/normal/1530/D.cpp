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
        vector<int> a(n+1,0);
        vector<int> b(n+1,0);
        vector<int> in(n+1,0);
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(in[a[i]]==0) b[i]=a[i];
            else v.push_back(i);
            in[a[i]]++;
        }
        vector<int> u;
        for(int i=1;i<=n;i++) if(in[i]==0) u.push_back(i);
        assert(v.size()==u.size());
        if(v.size()==1&&v[0]==u[0])
        {
            int x=a[v[0]];
            int y=0;
            for(int i=1;i<=n;i++) if(b[i]==x) y=i;
            b[v[0]]=x;
            b[y]=u[0];
        }
        else
        {
            vector<array<int,2>> opt;
            int sz=v.size();
            for(int i=0;i<sz;i++)
            {
                if(v[i]!=u.back())
                {
                    opt.push_back({v[i],u.back()});
                    u.pop_back();
                }
                else if(i<sz-1)
                {
                    opt.push_back({v[i],u[u.size()-2]});
                    swap(u[u.size()-2],u[u.size()-1]);
                    u.pop_back();
                }
                else
                {
                    opt.push_back({v[i],v[i]});
                    swap(opt[opt.size()-2][1],opt[opt.size()-1][1]);
                }
            }
            for(auto [x,y]:opt) b[x]=y;
        }
        int res=0;
        for(int i=1;i<=n;i++) res+=(a[i]==b[i]);
        cout << res << "\n";
        for(int i=1;i<=n;i++) cout << b[i] << " \n"[i==n];
    }
    return 0;
}