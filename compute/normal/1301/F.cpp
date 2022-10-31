#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
int dx[]={0,1,-1,0},dy[]={1,0,0,-1};
const int maxn=1030;
int a[maxn][maxn];
int n,m,k;
int dis[41][maxn][maxn];
int d[maxn*maxn];
bool vis[maxn*maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    auto getid=[&](int x,int y){
        return x*m+y;
    };
    vc<pi> col[k];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            col[a[i][j]-1].emplace_back(i,j);
        }
    for(int x=0;x<k;x++)
    {
        deque<int> q;
        memset(d,0x3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        d[n*m+x]=0;
        q.push_back(n*m+x);
        while(!q.empty())
        {
            auto u=q.front();q.pop_front();
            if(vis[u]) continue;
            vis[u]=1;
            if(u>=n*m)
            {
                for(auto v:col[u-n*m])
                {
                    int id=getid(v.first,v.second);
                    if(d[id]>d[u])
                    {
                        d[id]=d[u];
                        q.push_front(id);
                    }
                }
            }
            else{
                int cx=u/m,cy=u%m;
                int cc=a[cx][cy]-1;
                if(d[n*m+cc]>d[u]+1)
                {
                    q.push_back(n*m+cc);
                    d[n*m+cc]=d[u]+1;
                }
                for(int i=0;i<4;i++)
                {
                    int nx=cx+dx[i],ny=cy+dy[i];
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    int id=getid(nx,ny);
                    if(d[id]>d[u]+1)
                    {
                        d[id]=d[u]+1;
                        q.push_back(id);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
            {
                dis[x][i][j]=d[getid(i,j)];
                //if(x>=2)
                //dbg(i,j,dis[x][i][j]);
            }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;
        c1--;
        r2--;
        c2--;
        int ans=abs(r2-r1)+abs(c2-c1);
        for(int i=0;i<k;i++) ans=min(ans,dis[i][r1][c1]+dis[i][r2][c2]+1);
        print(ans);
    }

}