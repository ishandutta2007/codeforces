#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> v[N];
vector<int> vis(N,0);
vector<int> st;
vector<int> cycle;
vector<bool> dad(N,0);
vector<int> sz(N,0);

void dfs1(int a)
{
    vis[a]=1;
    st.push_back(a);
    for(int to:v[a])
    {
        if(vis[to]==0) dfs1(to);
        else if(vis[to]==1&&to!=st[st.size()-2])
        {
            bool b=0;
            for(int e:st)
            {
                if(e==to) b=1;
                if(b==1)
                {
                    cycle.push_back(e);
                    dad[e]=1;
                }
            }
        }
    }
    vis[a]=2;
    st.pop_back();
}

void dfs2(int a,int p=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p||dad[to]==1) continue;
        dfs2(to,a);
        sz[a]+=sz[to];
    }
}

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
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs1(1);
        for(int a:cycle) dfs2(a);
        ll res=((ll)n*(n-1)/2);
        ll sum=0;
        for(int a:cycle)
        {
            res+=(sum*sz[a]);
            sum+=sz[a];
        }
        cout << res << "\n";
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            vis[i]=0;
            dad[i]=0;
            sz[i]=0;
        }
        cycle.clear();
    }
    return 0;
}