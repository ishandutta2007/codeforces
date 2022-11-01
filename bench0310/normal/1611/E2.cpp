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
        int n,k;
        cin >> n >> k;
        vector<bool> f(n+1,0);
        for(int i=1;i<=k;i++)
        {
            int a;
            cin >> a;
            f[a]=1;
        }
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> c(n+1,0);
        vector<int> tin(n+1,0);
        vector<int> tout(n+1,0);
        vector<bool> leaf(n+1,0);
        int tcnt=0;
        function<int(int,int,int)> dfs=[&](int a,int p,int d)->int
        {
            tin[a]=++tcnt;
            if(a!=1&&v[a].size()==1) leaf[tin[a]]=1;
            int o=2*n;
            if(f[a]) o=d;
            for(int to:v[a])
            {
                if(to==p) continue;
                o=min(o,dfs(to,a,d+1));
            }
            if(o-d<=d) c[a]=1;
            tout[a]=tcnt;
            return o;
        };
        dfs(1,0,0);
        vector<int> mx(n+1,0);
        for(int i=1;i<=n;i++) if(c[i]) mx[tin[i]]=max(mx[tin[i]],tout[i]);
        for(int i=2;i<=n;i++) mx[i]=max(mx[i-1],mx[i]);
        int res=0;
        int a=2;
        while(a<=n)
        {
            while(a<=n&&!leaf[a]) a++;
            if(a==n+1) break;
            if(mx[a]>=a)
            {
                a=mx[a]+1;
                res++;
            }
            else
            {
                res=-1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}