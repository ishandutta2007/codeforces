#include <bits/stdc++.h>

using namespace std;

struct E
{
        int a;
        int b;
};

bool operator < (E x,E y)
{
        int xmi=min(x.a,x.b);
        int xma=max(x.a,x.b);
        int ymi=min(y.a,y.b);
        int yma=max(y.a,y.b);
        if(xmi!=ymi)
                return xmi<ymi;
        return xma<yma;
}

const int N=1000+7;
int n;
vector <int> g[N];
set <E> who[N];
vector <E> pat[N];
int cur;
bool vis[N];
vector <int> nodes[N];

void dfs(int nod)
{
        nodes[cur].push_back(nod);
        vis[nod]=1;
        for(auto &nou:g[nod])
        {
                who[cur].insert({nou,nod});
                if(!vis[nou])
                {
                        pat[cur].push_back({nod,nou});
                        dfs(nou);
                }
        }
}

vector <E> need;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>n;
        for(int i=1;i<n;i++)
        {
                int a,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
        }

        for(int i=1;i<=n;i++)
                if(!vis[i])
                {
                        cur++;
                        dfs(i);
                        for(auto &it : pat[cur])
                                who[cur].erase(it);
                }

        vector <E> extra;
        for(int i=1;i<=cur;i++)
                for(auto &it : who[i])
                        extra.push_back(it);

        for(int i=1;i+1<=cur;i++)
                need.push_back({nodes[i][0],nodes[i+1][0]});

        cout<<extra.size()<<"\n";

        for(int i=0;i<extra.size();i++)
                cout<<extra[i].a<<" "<<extra[i].b<<" "<<need[i].a<<" "<<need[i].b<<"\n";

        return 0;
}