#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=1000005;
vector<int> p(N);
vector<int> sz(N,1);
vector<int> g[N];
vector<int> in(N,0);

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
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> v(n,vector<int>(m,0));
    auto h=[&](int r,int c)->int{return r*m+c;};
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&v[o][i]);
            p[h(o,i)]=h(o,i);
        }
    }
    for(int o=0;o<n;o++)
    {
        map<int,int> x;
        for(int i=0;i<m;i++)
        {
            if(x.find(v[o][i])!=x.end()) merge_sets(x[v[o][i]],h(o,i));
            x[v[o][i]]=h(o,i);
        }
    }
    for(int i=0;i<m;i++)
    {
        map<int,int> x;
        for(int o=0;o<n;o++)
        {
            if(x.find(v[o][i])!=x.end()) merge_sets(x[v[o][i]],h(o,i));
            x[v[o][i]]=h(o,i);
        }
    }
    for(int o=0;o<n;o++)
    {
        vector<array<int,2>> x;
        for(int i=0;i<m;i++) x.push_back({v[o][i],find_set(h(o,i))});
        sort(x.begin(),x.end());
        for(int i=0;i<m-1;i++)
        {
            if(x[i][0]!=x[i+1][0])
            {
                g[x[i][1]].push_back(x[i+1][1]);
                in[x[i+1][1]]++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        vector<array<int,2>> x;
        for(int o=0;o<n;o++) x.push_back({v[o][i],find_set(h(o,i))});
        sort(x.begin(),x.end());
        for(int o=0;o<n-1;o++)
        {
            if(x[o][0]!=x[o+1][0])
            {
                g[x[o][1]].push_back(x[o+1][1]);
                in[x[o+1][1]]++;
            }
        }
    }
    vector<bool> ex(N,0);
    for(int i=0;i<n*m;i++) ex[find_set(i)]=1;
    vector<int> res(N,0);
    queue<array<int,2>> q;
    for(int i=0;i<n*m;i++) if(ex[i]==1&&in[i]==0) q.push({i,1});
    while(!q.empty())
    {
        auto [a,now]=q.front();
        q.pop();
        res[a]=now;
        for(int to:g[a])
        {
            in[to]--;
            if(in[to]==0) q.push({to,now+1});
        }
    }
    for(int o=0;o<n;o++) for(int i=0;i<m;i++) printf("%d%c",res[find_set(h(o,i))]," \n"[i==m-1]);
    return 0;
}