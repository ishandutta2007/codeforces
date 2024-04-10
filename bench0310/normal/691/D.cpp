#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
vector<int> p(N);
vector<int> sz(N,1);

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
    for(int i=1;i<=n;i++) p[i]=i;
    vector<int> x(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        merge_sets(a,b);
    }
    vector<int> v[n+1];
    for(int i=1;i<=n;i++) v[find_set(i)].push_back(x[i]);
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),greater<int>());
    vector<int> idx(n+1,0);
    for(int i=1;i<=n;i++) printf("%d%c",v[find_set(i)][idx[find_set(i)]++]," \n"[i==n]);
    return 0;
}