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
const int maxn=505;
int f[maxn][maxn][10][10];
int rsz[maxn][maxn];
int n,m,q;
inline int highbit(int x) { return 31 - __builtin_clz(x); }
inline int calc(int x, int y, int xx, int yy, int p, int q) {
    return max(
        max(f[x][y][p][q], f[xx - (1 << p) + 1][yy - (1 << q) + 1][p][q]),
        max(f[xx - (1 << p) + 1][y][p][q], f[x][yy - (1 << q) + 1][p][q])
    );
}
void init() {
    for(int x=0;x<highbit(n)+1;x++)
    for(int y=0;y<highbit(m)+1;y++)
        for (int i=0; i<n - (1 << x) + 1;i++)
        for (int j=0; j< m - (1 << y) + 1;j++) {
            if (!x && !y) { f[i][j][x][y] = rsz[i][j]; continue; }
            f[i][j][x][y] = calc(
                i, j,
                i + (1 << x) - 1, j + (1 << y) - 1,
                max(x - 1, 0), max(y - 1, 0)
            );
        }
}
inline int get_max(int x, int y, int xx, int yy) {
    if(xx<x||yy<y) return 0;
    return calc(x, y, xx, yy, highbit(xx - x + 1), highbit(yy - y + 1));
}
string maze[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++) cin>>maze[i];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(maze[i][j]=='R'&&maze[i][j+1]=='G'&&maze[i+1][j+1]=='B'&&maze[i+1][j]=='Y')
            {
                int sz=2;
                for(int k=1;;k++)
                {
                    if(i-k<0||j-k<0||i+k+1>=n||j+k+1>=m) break;
                    bool ok=1;
                    for(int ii=0;ii<=k;ii++)
                    {
                        if(maze[i-ii][j-k]!='R'||maze[i-k][j-ii]!='R') ok=0;
                        if(maze[i+1+k][j-ii]!='Y'||maze[i+1+ii][j-k]!='Y') ok=0;
                        if(maze[i-ii][j+1+k]!='G'||maze[i-k][j+1+ii]!='G') ok=0;
                        if(maze[i+1+ii][j+1+k]!='B'||maze[i+1+k][j+1+ii]!='B') ok=0;
                    }
                    if(ok) sz+=2;
                    else break;
                }
                rsz[i][j]=sz;
                dbg(i,j,sz);
            }
        }
    }
    init();
    while(q--)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;c1--;r2--;c2--;
        int L=1,R=min(r2-r1+1,c2-c1+1)/2,ans=0;
        while(L<=R)
        {
            int mid=L+R>>1;
            //dbg(L,R,mid,get_max(r1+mid-1,c1+mid-1,r2-mid,c2-mid));
            if(get_max(r1+mid-1,c1+mid-1,r2-mid,c2-mid)>=2*mid) ans=2*mid,L=mid+1;
            else R=mid-1;
        }
        //dbg(ans,get_max(r1+ans/2-1,c1+ans/2-1,r2-ans/2,c2-ans/2));
        print(ans*ans);
    }
}