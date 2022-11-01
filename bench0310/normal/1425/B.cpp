#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=4000;
const int mod=1000000007;

void add(int &a,ll b){a=(a+b)%mod;}

vector<int> solve(vector<int> v)
{
    vector<int> now(2*N+1,0);
    now[N]=1;
    for(int a:v)
    {
        vector<int> nxt=now;
        for(int i=-N;i+a<=N;i++) add(nxt[i+a+N],now[i+N]);
        for(int i=N;i-a>=-N;i--) add(nxt[i-a+N],now[i+N]);
        now=nxt;
    }
    return now;
}

vector<int> solve_force(vector<int> v)
{
    vector<int> now(2*N+1,0);
    now[N]=1;
    for(int a:v)
    {
        vector<int> nxt(2*N+1,0);
        for(int i=-N;i+a<=N;i++) add(nxt[i+a+N],now[i+N]);
        for(int i=N;i-a>=-N;i--) add(nxt[i-a+N],now[i+N]);
        now=nxt;
    }
    return now;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> g[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v;
    vector<bool> vis(n+1,0);
    vis[1]=1;
    for(int i:g[1])
    {
        if(vis[i]==1) continue;
        int now=i;
        int c=1;
        while(vis[now]==0)
        {
            c++;
            vis[now]=1;
            int nxt=g[now][0];
            if(vis[nxt]==1) nxt=g[now][1];
            now=nxt;
        }
        v.push_back(c);
    }
    set<int> s;
    for(int a:v) s.insert(a);
    vector<vector<int>> rm(n+1);
    vector<vector<int>> rm_force(n+1);
    for(int a:s)
    {
        vector<int> tmp;
        bool z=0;
        for(int b:v)
        {
            if(b==a&&z==0)
            {
                z=1;
                continue;
            }
            tmp.push_back(b);
        }
        rm[a]=solve(tmp);
        rm_force[a]=solve_force(tmp);
    }
    int res=0;
    for(int a:v)
    {
        //meet at a vertex
        for(int i=1;i<a;i++) add(res,2*rm[a][abs(a-2*i)+N]);
        //meet at an edge
        for(int i=1;i<a-1;i++) add(res,2*rm[a][abs(a-2*i-1)+N]);
        add(res,4ll*rm_force[a][a-1+N]);
    }
    if((m%2)==0) add(res,solve_force(v)[N]);
    cout << res << "\n";
    return 0;
}