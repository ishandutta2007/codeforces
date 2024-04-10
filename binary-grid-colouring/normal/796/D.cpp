#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
//multiset<int>s;
int main()
{	
    int n; int k,d;
    n=read();k=read();d=read();
    vector<int>a(n + 1);
    vector<int>dis(n+1,2e9); 
    vector<vector<pair<int, int>>> g(n + 1);
    for(int i=0;i<k;i++)
    {
    	int p;
    	p=read();
    	a[p]=1;
	}
    for (int i =0; i<n - 1; i++)
    {
    	int u,v;
    	u=read();
    	v=read();
    	g[u].push_back({v, i + 1}); 
		g[v].push_back({u, i + 1});
	}
	queue<int> que;
	for (int i = 1; i<=n; i++)
	{ 
		if (a[i])
		{ 
			dis[i] = 0; 
			que.push(i); 
		} 
	}
	while (!que.empty()) 
	{
	 	int u = que.front(); 
		que.pop(); 
		for (auto x : g[u])
		{ 
			int v = x.first; 
			if (dis[v] == 2e9)
			{
			 	dis[v] = dis[u] + 1; 
			 	que.push(v); 
			} 
		} 
	} 
	set<int> s; 
	for (int i = 1; i <= n; i++)
	{ 
		int flag = 0; 
		for (auto x : g[i])
		{ 
			int v = x.first;
			int id = x.second; 
			if (dis[v] <= dis[i])
			{ 
				if (flag==1|| dis[v] == dis[i])
				{ 
					s.insert(id);
				} 
				else
				{ 
					flag = 1; 
				} 
			} 
		} 
	}
	//If there are multiple answers
	// print any of them. 
	cout<<s.size()<<endl; 
	for(auto x : s)
	{ 
		cout<<x<<" "; 
	} 	
//	cout<<ans<<endl;
	return 0;
}