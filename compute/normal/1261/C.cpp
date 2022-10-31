#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;
const int maxn=1e6+7;
string maze[maxn];
string ans[maxn];
string cur[maxn];
int n,m;
bool check(int T)
{
    vector<vector<char> > a(n+2,vector<char>(m+2));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=maze[i-1][j-1];
    vector<vi> dp(n+2,vi(m+2));
    vector<vi> mark(n+2,vi(m+2));
    for(int i=0;i<n;i++)
    {
        cur[i]="";
        for(int j=0;j<m;j++) cur[i]+='.';
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=-dp[i-1][j-1]+dp[i][j-1]+dp[i-1][j]+(a[i][j]=='X');
    for(int i=T+1;i<=n-T;i++)
    {
        for(int j=T+1;j<=m-T;j++)
        {
            //dbg(i,j,T);
            if(a[i][j]=='X')
            {
                int rx=i+T,ry=j+T;
                int lx=i-T,ly=j-T;
                int sq=dp[rx][ry]-dp[rx][ly-1]-dp[lx-1][ry]+dp[lx-1][ly-1];
                if(sq==(2*T+1)*(2*T+1))
                {
                    cur[i-1][j-1]='X';
                    mark[lx][ly]++;
                    mark[rx+1][ry+1]++;
                    mark[lx][ry+1]--;
                    mark[rx+1][ly]--;
                }
            }
        }
    }
    vector<vi> pre(n+1,vi(m+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            pre[i][j]=-pre[i-1][j-1]+pre[i-1][j]+pre[i][j-1]+mark[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='X'&&!pre[i][j]) return false;
    return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>maze[i];
	int L=0,R=min(n,m)/2;
	int op=0;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))
		{
			L=mid+1;
			op=mid;
			for(int i=0;i<n;i++) ans[i]=cur[i];
		}
		else R=mid-1;
	}
	cout<<op<<endl;
	for(int i=0;i<n;i++) cout<<ans[i]<<'\n';
}