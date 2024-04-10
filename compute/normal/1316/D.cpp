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
const int maxn=1e3+7;
bool ok=1;
int x[maxn][maxn],y[maxn][maxn];
char ans[maxn][maxn];
int dx[]={0,1,-1,0},dy[]={1,0,0,-1};
bool vis[maxn][maxn];
int n;
void dfs(pi cur,pi st)
{
    vis[cur.first][cur.second]=1;
    for(int i=0;i<4;i++)
    {
        int nx=cur.first+dx[i],ny=cur.second+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n) continue;
        if(x[nx][ny]!=st.first||y[nx][ny]!=st.second) continue;
        if(vis[nx][ny]) continue;
        if(i==0)
            ans[nx][ny]='L';
        else if(i==1) ans[nx][ny]='U';
        else if(i==2) ans[nx][ny]='D';
        else ans[nx][ny]='R';
        dfs(make_pair(nx,ny),st);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    vc<pi> st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x[i][j]>>y[i][j];
            if(x[i][j]==i+1&&y[i][j]==j+1)
                st.emplace_back(i,j);
        }
    }
    for(auto u:st)
    {
        ans[u.first][u.second]='X';
        pi tar=u;
        tar.first++;
        tar.second++;
        dfs(u,tar);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(vis[i][j]) continue;
            if(x[i][j]==-1&&y[i][j]==-1)
            {
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k],ny=j+dy[k];
                    if(nx<0||nx>=n||ny<0||ny>=n) continue;
                    if(x[nx][ny]==-1&&y[nx][ny]==-1)
                    {
                        if(!vis[nx][ny])
                        {
                            if(k==0)
                                ans[nx][ny]='L';
                            else if(k==1) ans[nx][ny]='U';
                            else if(k==2) ans[nx][ny]='D';
                            else ans[nx][ny]='R';
                            vis[nx][ny]=1;
                        }
                        if(k==0)
                                ans[i][j]='R';
                        else if(k==1) ans[i][j]='D';
                        else if(k==2) ans[i][j]='U';
                        else ans[i][j]='L';
                        vis[i][j]=1;
                        break;
                    }
                }
                if(!vis[i][j]) ok=0;
            }
            else{
                ok=0;
            }
        }
    }
    if(!ok) cout<<"INVALID\n";
    else{
        cout<<"VALID\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) cout<<ans[i][j];
            cout<<'\n';
        }
    }
}