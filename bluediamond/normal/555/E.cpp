#include <bits/stdc++.h>

using namespace std;

struct T
{
        int a;
        int b;
};

bool operator < (T f,T s)
{
        if(f.a>f.b) swap(f.a,f.b);
        if(s.a>s.b) swap(s.a,s.b);
        if(f.a!=s.a)
                return f.a<s.a;
        return f.b<s.b;
}

const int N=(int)2e5+7;
int n,m,op;
vector <int> g[N];
map <T,int> cnted;
bool visited[N];
int dep1[N];
int mn_val[N];
set <T> bridges;
int curC;
int component[N];

void rundfs(int nod,int par)
{
        component[nod]=curC;
        vector <int> up;
        vector <int> dw;
        visited[nod]=1;
        for(auto &nou : g[nod])
        {
                if(nou==par)
                        continue;
                if(visited[nou])
                        up.push_back(nou);
                else
                {
                        dep1[nou]=1+dep1[nod];
                        rundfs(nou,nod);
                        dw.push_back(nou);
                }
        }
        mn_val[nod]=(1<<30);
        for(auto &nou : up)
                mn_val[nod]=min(mn_val[nod],dep1[nou]);
        for(auto &nou : dw)
                mn_val[nod]=min(mn_val[nod],mn_val[nou]);
        for(auto &nou : dw)
                if(mn_val[nou]>dep1[nod])
                        bridges.insert({nod,nou});
}

bool AV_edge(int a,int b)
{
        return (bridges.find({a,b})==bridges.end());
}

int color[N],curCOLOR;

void coloring(int nod)
{
        color[nod]=curCOLOR;
        for(auto &nou : g[nod])
                if(AV_edge(nod,nou) && color[nou]==0)
                        coloring(nou);
}

void transit_graf()
{
        for(int i=1;i<=n;i++)
                if(color[i]==0)
                {
                        curCOLOR++;
                        coloring(i);
                }
        for(int i=1;i<=n;i++)
                g[i].clear();
        n=curCOLOR;
        for(auto &it : bridges)
        {
                int a=color[it.a];
                int b=color[it.b];
                g[a].push_back(b);
                g[b].push_back(a);
        }
}

const int DUB=2*N;
const int L=20;

int my_log[DUB];
pair <int,int> rmq[L][DUB];
int euler[DUB],sz;
int first[N];
int last[N];
int dep2[N];

void dfs_euler(int nod)
{
        euler[++sz]=nod;
        visited[nod]=1;
        for(auto &nou : g[nod])
                if(visited[nou]==0)
                {
                        dep2[nou]=1+dep2[nod];
                        dfs_euler(nou);
                        euler[++sz]=nod;
                }
}

int lca(int a,int b)
{
        int st=first[a];
        int dr=last[b];
        if(st>dr)
              swap(a,b);
        st=first[a];
        dr=last[b];
        int k=my_log[dr-st+1];
        return min(rmq[k][st],rmq[k][dr-(1<<k)+1]).second;
}

int x[N];
int y[N];

void final_check(int nod)
{
        visited[nod]=1;
        for(auto &nou : g[nod])
                if(visited[nou]==0)
                {
                        final_check(nou);
                        x[nod]+=x[nou];
                        y[nod]+=y[nou];
                }
        if(x[nod] && y[nod])
        {
                cout<<"No\n";
                exit(0);
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m>>op;
        for(int i=1;i<=m;i++)
        {
                int a,b;
                cin>>a>>b;
                g[a].push_back(b);
                g[b].push_back(a);
                cnted[{a,b}]++;
        }

        for(int i=1;i<=n;i++)
                if(visited[i]==0)
                {
                        curC++;
                        rundfs(i,-1);
                }
        for(auto &it : cnted)
                if(it.second>=2)
                        bridges.erase(it.first);

        transit_graf();
        for(int i=2;i<DUB;i++)
                my_log[i]=1+my_log[i/2];

        for(int i=1;i<=n;i++)
                visited[i]=0;

        for(int i=1;i<=n;i++)
                if(visited[i]==0)
                        dfs_euler(i);

        for(int i=1;i<=sz;i++)
                last[euler[i]]=i;
        for(int i=sz;i>=1;i--)
                first[euler[i]]=i;
        for(int i=1;i<=sz;i++)
                rmq[0][i]={dep2[euler[i]],euler[i]};

        for(int k=1;(1<<k)<=sz;k++)
                for(int i=1;i+(1<<k)-1<=sz;i++)
                        rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+(1<<(k-1))]);

        for(int i=1;i<=op;i++)
        {
                int a,b;
                cin>>a>>b;
                if(component[a]!=component[b])
                {
                        cout<<"No\n";
                        return 0;
                }
                a=color[a];
                b=color[b];
                int c=lca(a,b);
                x[a]++;
                x[c]--;
                y[b]++;
                y[c]--;
        }

        for(int i=1;i<=n;i++)
                visited[i]=0;
        for(int i=1;i<=n;i++)
                if(visited[i]==0)
                        final_check(i);
        cout<<"Yes\n";
        return 0;
}