#include <bits/stdc++.h>

using namespace std;
const int N=100005;

vector<int> tree[N];
int id[N];
int dist[N];
int sz[N];

void update(int idd,int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idd][idx]=val;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(idd,2*idx,l,m,pos,val);
        else update(idd,2*idx+1,m+1,r,pos,val);
        tree[idd][idx]=tree[idd][2*idx]+tree[idd][2*idx+1];
    }
}

int query(int idd,int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idd][idx];
    int m=(l+r)/2;
    return query(idd,2*idx,l,m,ql,min(m,qr))+query(idd,2*idx+1,m+1,r,max(m+1,ql),qr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    cin >> n;
    vector<int> v[n+1];
    vector<pair<int,int> > edges(n-1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        edges[i]=make_pair(a,b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int root,buff=0;
    for(int i=1;i<=n;i++)
    {
        if((int)v[i].size()>buff)
        {
            buff=v[i].size();
            root=i;
        }
    }
    queue<int> q;
    vector<bool> vis(n+1,0);
    vis[root]=1;
    dist[root]=0;
    int num=v[root].size();
    for(int i=0;i<num;i++)
    {
        q.push(v[root][i]);
        vis[v[root][i]]=1;
        dist[v[root][i]]=1;
        id[v[root][i]]=i;
        sz[i]=1;
    }
    while(!q.empty())
    {
        int e=q.front();
        q.pop();
        for(int i=0;i<(int)v[e].size();i++)
        {
            if(!vis[v[e][i]])
            {
                vis[v[e][i]]=1;
                q.push(v[e][i]);
                dist[v[e][i]]=dist[e]+1;
                id[v[e][i]]=id[e];
                sz[id[e]]=dist[e]+1;
            }
        }
    }
    /*cout << "id: " << endl;
    for(int i=1;i<=n;i++) cout << id[i] << " ";
    cout << endl;
    cout << "dist: " << endl;
    for(int i=1;i<=n;i++) cout << dist[i] << " ";
    cout << endl;
    cout << "sz: " << endl;
    for(int i=0;i<=n;i++) cout << sz[i] << " ";
    cout << endl;*/
    for(int o=0;o<num;o++) for(int i=0;i<4*(sz[o]);i++) tree[o].push_back(0);
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int type;
        cin >> type;
        type--;
        if(type==0||type==1)
        {
            int idx;
            cin >> idx;
            idx--;
            int a=edges[idx].first;
            int b=edges[idx].second;
            if(dist[a]>=dist[b]) swap(a,b);
            update(id[b],1,1,sz[id[b]],dist[b],type);
        }
        else
        {
            int a,b;
            cin >> a >> b;
            if(a==b) cout << 0 << endl;
            else
            {
                if(dist[a]>=dist[b]) swap(a,b);
                if(a==root) id[root]=id[b];
                if(id[a]==id[b])
                {
                    if(query(id[a],1,1,sz[id[b]],dist[a]+1,dist[b])==0) cout << dist[b]-dist[a] << endl;
                    else cout << -1 << endl;
                }
                else
                {
                    if(query(id[a],1,1,sz[id[a]],1,dist[a])==0&&query(id[b],1,1,sz[id[b]],1,dist[b])==0) cout << dist[a]+dist[b] << endl;
                    else cout << -1 << endl;
                }
            }
        }
    }
    return 0;
}