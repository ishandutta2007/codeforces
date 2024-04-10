#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=201;
vector<vector<int>> v(N+1);
vector<vector<int>> f(N+1,vector<int>(N+1,0));
vector<vector<int>> c(N+1,vector<int>(N+1,0));
vector<bool> vis(N+1,0);
vector<int> tmp;

bool dfs(int a)
{
    tmp.push_back(a);
    if(a==N) return 1;
    vis[a]=1;
    for(int to:v[a])
    {
        if(vis[to]==0&&c[a][to]-f[a][to]>0&&dfs(to)==1) return 1;
    }
    tmp.pop_back();
    return 0;
}

int augment()
{
    for(int i=0;i<=N;i++) vis[i]=0;
    if(dfs(0)==1)
    {
        for(int i=0;i<(int)tmp.size()-1;i++)
        {
            int a=tmp[i];
            int b=tmp[i+1];
            f[a][b]++;
            f[b][a]--;
        }
        tmp.clear();
        return 1;
    }
    else return 0;
}

void out()
{
    cout << "Impossible\n";
    exit(0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int M=20000;
    vector<bool> prime(M+1,1);
    for(int i=2;i<=M;i++)
    {
        if(prime[i]==0) continue;
        for(int j=i*i;j<=M;j+=i) prime[j]=0;
    }
    int n;
    cin >> n;
    vector<int> val(n+1,0);
    for(int i=1;i<=n;i++) cin >> val[i];
    vector<int> one,two;
    auto add=[&](int a,int b)
    {
        v[a].push_back(b);
        v[b].push_back(a);
    };
    for(int i=1;i<=n;i++)
    {
        if((val[i]%2)==0) one.push_back(i);
        else two.push_back(i);
        for(int j=1;j<=n;j++)
        {
            if((val[i]%2)==0&&prime[val[i]+val[j]]==1)
            {
                add(i,j);
                c[i][j]=1;
            }
        }
    }
    if(one.size()!=two.size()) out();
    for(int a:one)
    {
        add(0,a);
        c[0][a]=2;
    }
    for(int a:two)
    {
        add(a,N);
        c[a][N]=2;
    }
    int flow=0;
    while(augment()==1) flow++;
    if(flow<n) out();
    vector<int> g[n+1];
    for(int a:one)
    {
        for(int b:two)
        {
            if(f[a][b]==1)
            {
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
    }
    vector<vector<int>> res;
    for(int i=1;i<=n;i++) vis[i]=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) continue;
        vector<int> now={i,g[i][0]};
        while(now.size()==2||(g[now.back()][0]!=i&&g[now.back()][1]!=i))
        {
            int x=0;
            if(g[now.back()][0]==now[now.size()-2]) x=1;
            now.push_back(g[now.back()][x]);
        }
        for(int a:now) vis[a]=1;
        res.push_back(now);
    }
    cout << res.size() << "\n";
    for(vector<int> &a:res)
    {
        cout << a.size();
        for(int b:a) cout << " " << b;
        cout << "\n";
    }
    return 0;
}