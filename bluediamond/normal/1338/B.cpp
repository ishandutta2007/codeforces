#include <bits/stdc++.h>

using namespace std;

const int N=(int) 1e5+7;
int n,has[N],ans,k[N];
vector<int> g[N];
bool via[N];

void DFS(int a)
{
        via[a]=1;
        for (auto &b : g[a])
                if (!via[b])
                {
                        DFS(b);
                        if (has[b]&1) has[a]|=2;
                        if (has[b]&2) has[a]|=1;
                }
        has[a]=max(has[a],1);
}

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        cin>>n;
        for (int i=1;i<n;i++)
        {
                int x,y;
                cin>>x>>y;
                g[x].push_back(y);
                g[y].push_back(x);
        }
        int R=1;
        while ((int)g[R].size()>1)
                R++;
        DFS(R);
        for (int i=1;i<=n;i++)
                if ((int)g[i].size()==1)
                        k[g[i][0]]++;
        for (int i=1;i<=n;i++)
                ans-=max(0,k[i]-1);
        ans+=n-1;
        cout<<1+(has[R]&2)<<" "<<ans<<"\n";
}