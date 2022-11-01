#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> to(2*n+1,{0,0});
    for(int i=1;i<=2*n;i++)
    {
        int x,y;
        cin >> x >> y;
        to[x][to[x][0]!=0]=y;
        to[y][to[y][0]!=0]=x;
    }
    vector<bool> vis(2*n+1,0);
    ll res=0;
    for(int i=1;i<=2*n;i++)
    {
        if(vis[i]) continue;
        vector<int> v={i};
        vis[i]=1;
        while(1)
        {
            int a=v.back();
            int b=to[a][vis[to[a][0]]];
            if(vis[b]) break;
            vis[b]=1;
            v.push_back(b);
        }
        int sz=v.size();
        for(int l=0;l<sz;l++)
        {
            int lmn=2*n+1,lmx=0;
            int rmn=2*n+1,rmx=0;
            int len=0;
            for(int r=l;r!=(l-1+sz)%sz;r=(r+1)%sz)
            {
                len++;
                int a=v[r];
                if(a<=n)
                {
                    lmn=min(lmn,a);
                    lmx=max(lmx,a);
                }
                else
                {
                    rmn=min(rmn,a);
                    rmx=max(rmx,a);
                }
                int badllow=0;
                int badlhigh=n+1;
                int badrlow=n;
                int badrhigh=2*n+1;
                bool ok=1;
                auto upd=[&](int bad)
                {
                    if(bad<=n)
                    {
                        if(lmn<=bad&&bad<=lmx) ok=0;
                        else if(bad<lmn) badllow=max(badllow,bad);
                        else badlhigh=min(badlhigh,bad);
                    }
                    else
                    {
                        if(rmn<=bad&&bad<=rmx) ok=0;
                        else if(bad<rmn) badrlow=max(badrlow,bad);
                        else badrhigh=min(badrhigh,bad);
                    }
                };
                upd(v[(l-1+sz)%sz]);
                upd(v[(r+1)%sz]);
                if(ok)
                {
                    ll now=ll(lmn-badllow)*ll(badlhigh-lmx)*ll(rmn-badrlow)*ll(badrhigh-rmx);
                    int cnt=(len/2);
                    res+=(now*cnt);
                }
            }
            if(l==0)
            {
                int a=v[(l-1+sz)%sz];
                if(a<=n)
                {
                    lmn=min(lmn,a);
                    lmx=max(lmx,a);
                }
                else
                {
                    rmn=min(rmn,a);
                    rmx=max(rmx,a);
                }
                ll now=ll(lmn)*ll(n+1-lmx)*ll(rmn-n)*ll(2*n+1-rmx);
                res+=(now*(sz/2));
            }
        }
    }
    cout << res << "\n";
    return 0;
}