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
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> c(30,0);
        vector e(30,vector(30,int(0)));
        auto ch=[&](int x,int d)
        {
            int p=-1;
            for(int i=0;i<30;i++)
            {
                if(x&(1<<i))
                {
                    c[i]+=d;
                    if(p!=-1)
                    {
                        e[p][i]+=d;
                        e[i][p]+=d;
                    }
                    p=i;
                }
            }
        };
        auto cool=[&]()->bool
        {
            int cc=0;
            vector<bool> vis(30,0);
            for(int i=0;i<30;i++)
            {
                if(c[i]==0||vis[i]) continue;
                if((++cc)==2) return 0;
                function<void(int)> dfs=[&](int x)
                {
                    vis[x]=1;
                    for(int b=0;b<30;b++) if(e[x][b]>0&&!vis[b]&&c[b]>0) dfs(b);
                };
                dfs(i);
            }
            return 1;
        };
        cout << [&]()->int
        {
            int res=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    res++;
                    a[i]=1;
                }
            }
            for(int i=1;i<=n;i++) ch(a[i],1);
            if(cool()) return res;
            for(int i=1;i<=n;i++)
            {
                for(int d=-1;d<=1;d+=2)
                {
                    if(a[i]+d==0) continue;
                    ch(a[i],-1);
                    ch(a[i]+d,1);
                    if(cool())
                    {
                        a[i]+=d;
                        return res+1;
                    }
                    ch(a[i]+d,-1);
                    ch(a[i],1);
                }
            }
            vector<int> lsb(n+1,-1);
            int m=-1;
            for(int i=1;i<=n;i++)
            {
                lsb[i]=countr_zero(uint32_t(a[i]));
                m=max(m,lsb[i]);
            }
            int one=0;
            for(int i=1;i<=n;i++)
            {
                if(lsb[i]==m)
                {
                    if(one==0)
                    {
                        a[i]--;
                        one=1;
                    }
                    else
                    {
                        a[i]++;
                        return res+2;
                    }
                }
            }
            return -1;
        }() << "\n";
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}