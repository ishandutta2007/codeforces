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
        int n,q;
        cin >> n >> q;
        vector<int> a(n+1,0);
        vector<int> x(n+1,0);
        vector<array<int,30>> prv(n+1);
        vector<array<int,30>> nxt(n+2);
        vector<array<int,30>> cnt(n+1);
        prv[0].fill(0);
        nxt[n+1].fill(0);
        cnt[0].fill(0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            x[i]=(x[i-1]^a[i]);
            prv[i]=prv[i-1];
            cnt[i]=cnt[i-1];
            for(int j=0;j<30;j++)
            {
                if(a[i]&(1<<j))
                {
                    prv[i][j]=i;
                    cnt[i][j]++;
                }
            }
        }
        for(int i=n;i>=1;i--)
        {
            nxt[i]=nxt[i+1];
            for(int j=0;j<30;j++) if(a[i]&(1<<j)) nxt[i][j]=i;
        }
        while(q--)
        {
            int l,r;
            cin >> l >> r;
            int liml=r,limr=l;
            vector<array<int,2>> e;
            for(int j=0;j<30;j++)
            {
                int c=cnt[r][j]-cnt[l-1][j];
                if(c<=1) continue;
                int lx=nxt[l][j];
                int rx=prv[r][j];
                if(c&1)
                {
                    int ly=nxt[lx+1][j];
                    int ry=prv[rx-1][j];
                    liml=min(liml,ly);
                    limr=max(limr,ry);
                    e.push_back({lx+1,rx});
                }
                else
                {
                    liml=min(liml,lx);
                    limr=max(limr,rx);
                }
            }
            e.push_back({l-1,0});
            e.push_back({liml+1,0});
            ranges::sort(e);
            array<int,3> res={r-l+1,l,r};
            for(int i=0;i+1<(int)e.size();i++)
            {
                if(e[i][0]==liml+1) break;
                limr=max(limr,e[i][1]);
                if(e[i][0]==e[i+1][0]) continue;
                int tl=e[i+1][0]-1;
                int tr=max(limr,tl);
                if(l<=tl&&tl<=liml&&tr<=r) res=min(res,{tr-tl+1,tl,tr});
            }
            cout << res[1] << " " << res[2] << "\n";
        }
    }
    return 0;
}