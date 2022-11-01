#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<set<int>> v(N);
vector<int> sz(N,0);
vector<int> res(N,0);

void find_sz(int a,int p=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==p) continue;
        find_sz(to,a);
        sz[a]+=sz[to];
    }
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

void build_cd(int a,int d=1)
{
    find_sz(a);
    int n=sz[a];
    int centroid=find_centroid(a,0,n);
    res[centroid]=d;
    for(int to:v[centroid])
    {
        v[to].erase(centroid);
        build_cd(to,d+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<bool> vis(n+1,0);
    vector<int> r(n+1,0);
    for(int i=1;i<=n;i++) r[i]=(i<=n-1?i+1:1);
    auto dist=[&](int a,int b)->int
    {
        if(a<=b) return b-a;
        else return n-a+b;
    };
    vector<array<int,2>> d(m);
    for(int i=0;i<m;i++)
    {
        cin >> d[i][0] >> d[i][1];
        if(dist(d[i][0],d[i][1])>dist(d[i][1],d[i][0])) swap(d[i][0],d[i][1]);
    }
    sort(d.begin(),d.end(),[&](const array<int,2> &a,const array<int,2> &b){return (dist(a[0],a[1])<dist(b[0],b[1]));});
    vector<vector<int>> vertices;
    for(auto [a,b]:d)
    {
        vector<int> now;
        now.push_back(a);
        while(r[a]!=b)
        {
            now.push_back(r[a]);
            vis[r[a]]=1;
            r[a]=r[r[a]];
        }
        now.push_back(b);
        sort(now.begin(),now.end(),greater<int>());
        vertices.push_back(now);
    }
    vector<int> now;
    for(int i=1;i<=n;i++) if(vis[i]==0) now.push_back(i);
    sort(now.begin(),now.end(),greater<int>());
    vertices.push_back(now);
    sort(vertices.begin(),vertices.end());
    map<array<int,2>,vector<int>> id;
    for(int i=0;i<(int)vertices.size();i++)
    {
        for(int j=(int)vertices[i].size()-1;j>0;j--) id[{vertices[i][j],vertices[i][j-1]}].push_back(i+1);
        id[{vertices[i].back(),vertices[i][0]}].push_back(i+1);
    }
    for(auto [a,b]:d)
    {
        if(a>b) swap(a,b);
        int one=id[{a,b}][0];
        int two=id[{a,b}][1];
        v[one].insert(two);
        v[two].insert(one);
    }
    build_cd(1);
    for(int i=1;i<=m+1;i++) cout << res[i] << " \n"[i==m+1];
    return 0;
}