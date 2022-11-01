#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> p(N);
vector<long long> sz(N,1);
long long res=0;

int find_set(int a)
{
    if(a==p[a]) return a;
    else return p[a]=find_set(p[a]);
}

void merge_sets(int a,int b,long long w)
{
    a=find_set(a);
    b=find_set(b);
    if(a==b) return;
    res+=(w*sz[a]*sz[b]);
    if(sz[a]<sz[b]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) p[i]=i;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<array<int,3>> v(m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[i]={min(a[x],a[y]),x,y};
    }
    sort(v.begin(),v.end(),greater<array<int,3>>());
    for(auto e:v) merge_sets(e[1],e[2],e[0]);
    double t=(double)res/((long long)n*(n-1)/2);
    cout << fixed << setprecision(14) << t << endl;
    return 0;
}