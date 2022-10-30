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
const int INF=0x3f3f3f3f;
const int maxn = 80;
int n; //
int cost[maxn][maxn];
int lx[maxn], ly[maxn], match[maxn], slack[maxn];
int pprev[maxn];
bool vy[maxn];
void augment(int root)
{
    memset(vy, 0, sizeof(vy));
    memset(slack, 0x3f, sizeof(slack));
    int py;
    match[py = 0] = root;
    do
    {
        vy[py] = true;
        int x = match[py], yy;
        int delta = INF;
        for (int y = 1; y <= n; y++)
        {
            if (!vy[y])
            {
                if (lx[x] + ly[y] - cost[x][y] < slack[y])
                    slack[y] = lx[x] + ly[y] - cost[x][y], pprev[y] = py;
                if (slack[y] < delta)
                    delta = slack[y], yy = y;
            }
        }
        for (int y = 0; y <= n; y++)
        {
            if (vy[y])
                lx[match[y]] -= delta, ly[y] += delta;
            else
                slack[y] -= delta;
        }
        py = yy;
    } while (match[py] != -1);
    do
    {
        int pre = pprev[py];
        match[py] = match[pre], py = pre;
    } while (py);
}
int KM()
{
    for (int i = 1; i <= n; i++)
    {
        lx[i] = ly[i] = 0;
        match[i] = -1;
        for (int j = 1; j <= n; j++)
            lx[i] = max(lx[i], cost[i][j]);
    }
    int ans = 0;
    for (int root = 1; root <= n; root++)
        augment(root);
    for (int i = 1; i <= n; i++)
        ans += lx[i], ans += ly[i];
    return ans;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int a,b;
			cin>>a>>b;
			for(int j=1;j<=n;j++)
			{
				if(j<=k)
					cost[i][j]=(j-1)*b+a;
				else cost[i][j]=(k-1)*b;
			}
		}
		KM();
		vi ans;
		for(int i=1;i<k;i++) ans.push_back(match[i]);
		for(int i=k+1;i<=n;i++)
		{
			ans.push_back(match[i]);
			ans.push_back(-match[i]);
		}
		ans.push_back(match[k]);
		print(ans.size());
		print(ans);
	}
}