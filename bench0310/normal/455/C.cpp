#include <bits/stdc++.h>

using namespace std;

const int N=300005;
vector<int> v[N];
vector<int> d(N,-1);
vector<int> p(N,0);
vector<int> sz(N,1);
vector<int> res(N,1);

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

void merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
    int one=res[a]/2+1;
    int two=res[b]/2+1;
    res[a]=max(one+two,max(res[a],res[b]));
}

void ini(int a)
{
    d[a]=0;
    queue<int> q;
    vector<int> t;
    q.push(a);
    int src=a;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        t.push_back(x);
        for(int to:v[x])
        {
            if(d[to]!=-1) continue;
            d[to]=d[x]+1;
            if(d[to]>d[src]) src=to;
            q.push(to);
        }
    }
    for(int x:t) d[x]=-1;
    d[src]=1;
    q.push(src);
    int best=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        t.push_back(x);
        for(int to:v[x])
        {
            if(d[to]!=-1) continue;
            d[to]=d[x]+1;
            best=max(best,d[to]);
            q.push(to);
        }
    }
    res[find_set(a)]=best;
}

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
        merge_sets(a,b);
    }
    for(int i=1;i<=n;i++) if(d[i]==-1) ini(i);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int a;
            scanf("%d",&a);
            printf("%d\n",res[find_set(a)]-1);
        }
        else if(t==2)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            merge_sets(a,b);
        }
    }
    return 0;
}