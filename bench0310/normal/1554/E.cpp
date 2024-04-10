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
        vector<array<int,2>> edges;
        vector<int> deg(n+1,0);
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            edges.push_back({a,b});
            deg[a]++; deg[b]++;
        }
        const int mod=998244353;
        vector<int> res(n+1,1);
        for(int k=2;k<=n;k++)
        {
            if(((n-1)%k)==0)
            {
                vector<int> v[n+1];
                vector<int> d=deg;
                vector<int> e(n+1,0);
                vector<bool> vis(n+1,0);
                for(auto [a,b]:edges)
                {
                    res[k]&=(d[a]>=k||d[b]>=k);
                    if(d[a]>=k&&d[b]>=k)
                    {
                        v[a].push_back(b);
                        v[b].push_back(a);
                        e[a]++; e[b]++;
                    }
                }
                queue<int> q;
                for(int i=1;i<=n;i++)
                {
                    if(d[i]>=k&&e[i]<=1)
                    {
                        q.push(i);
                        vis[i]=1;
                    }
                }
                while(!q.empty())
                {
                    int a=q.front();
                    q.pop();
                    res[k]&=((d[a]%k)<=1);
                    if(e[a]==0) res[k]&=((d[a]%k)==0);
                    else
                    {
                        int to=0;
                        for(int b:v[a]) if(!vis[b]) to=b;
                        d[to]-=((d[a]%k)==0);
                        if((--e[to])==1&&vis[to]==0)
                        {
                            q.push(to);
                            vis[to]=1;
                        }
                    }
                }
            }
            else res[k]=0;
        }
        for(int i=1;i<=n-1;i++) res[1]=(2*res[1])%mod;
        for(int i=n;i>=1;i--) for(int j=2*i;j<=n;j+=i) res[i]=(res[i]-res[j]+mod)%mod;
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}