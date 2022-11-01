#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n+1,0);
        vector<array<int,2>> h(n);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            h[i-1]={a[i],i};
        }
        ranges::sort(h);
        int id=0;
        for(int i=0;i<n;i++)
        {
            auto [x,p]=h[i];
            if(i==0||h[i-1][0]!=x) id++;
            a[p]=id;
        }
        vector<int> nxt(n+1,0);
        vector<int> now(n+1,0);
        vector<int> pos[n+1];
        for(int i=1;i<=n;i++) pos[a[i]].push_back(i);
        for(int i=n;i>=1;i--)
        {
            nxt[i]=now[a[i]];
            now[a[i]]=i;
        }
        auto prv=[&](int x,int p)->int
        {
            int t=ranges::upper_bound(pos[x],p)-pos[x].begin()-1;
            return pos[x][t];
        };
        vector<int> mx(n+1,0);
        for(int i=1;i<=m;i++)
        {
            int l,r;
            cin >> l >> r;
            mx[l]=max(mx[l],r);
        }
        vector<array<int,2>> v;
        int lim=0;
        for(int i=1;i<=n;i++)
        {
            lim=max(lim,mx[i]);
            if(lim<i) continue;
            int p=prv(a[i],lim);
            if(i<p) v.push_back({i,p});
            if(nxt[i]!=0&&nxt[i]<=lim) v.push_back({i,nxt[i]});
        }
        vector<int> mxr(n+1,0);
        int lmx=0;
        int rmn=n+1;
        for(auto [l,r]:v)
        {
            lmx=max(lmx,l);
            rmn=min(rmn,r);
            mxr[l]=max(mxr[l],r);
        }
        int res=0;
        if(!v.empty())
        {
            res=n;
            int req=0;
            for(int i=1;i<=rmn;i++)
            {
                int to=max(req,lmx);
                res=min(res,to-i+1);
                req=max(req,mxr[i]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}