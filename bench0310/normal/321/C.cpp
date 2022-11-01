#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<set<int>> v(N);
vector<int> sz(N,0);
vector<char> res(N);

int find_sz(int a,int p=-1)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
    return sz[a];
}

int find_centroid(int a,int p,int n)
{
    for(int to:v[a])
    {
        if(to==p) continue;
        if(sz[to]>n/2) return find_centroid(to,a,n);
    }
    return a;
}

void build_cd(int a,int p=-1,int d=0)
{
    int n=find_sz(a);
    int centroid=find_centroid(a,p,n);
    res[centroid]=(d+'A');
    for(int to:v[centroid])
    {
        v[to].erase(centroid);
        build_cd(to,centroid,d+1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].insert(b);
        v[b].insert(a);
    }
    build_cd(1);
    for(int i=1;i<=n;i++) printf("%c%c",res[i]," \n"[i==n]);
    return 0;
}