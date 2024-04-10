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
        vector<array<int,3>> v(n+1,{0,0,0});
        vector<array<int,4>> h; //sum,l,r,i
        for(int i=1;i<=n;i++)
        {
            auto &[a,b,m]=v[i];
            cin >> a >> b >> m;
            int l=max(0,a-m);
            int r=a-max(0,m-b);
            h.push_back({a+b-m,l,r,i});
        }
        ranges::sort(h);
        int cnt=0;
        vector<int> res(n+1,0);
        int x=0;
        while(x<n)
        {
            int y=x;
            while(y+1<n&&h[y+1][0]==h[x][0]) y++;
            vector<array<int,3>> u;
            for(int i=x;i<=y;i++) u.push_back({h[i][1],h[i][2],h[i][3]});
            int sz=u.size();
            int now=0;
            while(now<sz)
            {
                int lim=u[now][1];
                int nxt=now;
                while(nxt+1<sz&&u[nxt+1][0]<=lim)
                {
                    nxt++;
                    lim=min(lim,u[nxt][1]);
                }
                cnt++;
                for(int i=now;i<=nxt;i++) res[u[i][2]]=lim;
                now=nxt+1;
            }
            x=y+1;
        }
        cout << cnt << "\n";
        for(int i=1;i<=n;i++)
        {
            auto [a,b,m]=v[i];
            int r=a-res[i];
            int y=m-r;
            cout << r << " " << y << "\n";
        }
    }
    return 0;
}