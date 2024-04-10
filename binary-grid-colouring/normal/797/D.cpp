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
const int INF = 2e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =123456; 
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

//int dp[400][101000];
int a[N],b[N],c[N];
set<int>s;
void dfs(int u,int l,int r)//dfs
{
	if(u==-1||r<l)return ;
	if(a[u]>=l&&a[u]<=r){
		s.insert(a[u]);
	}
	dfs(b[u],l,min(r,a[u]-1));
	dfs(c[u],max(l,a[u]+1),r);
}
map<int,int>mp;
int main()
{
	//in;
	int n;
	n=read();
	vector<int>v(n+1);
	for(int i=1;i<=n;i++){
		a[i]=read(),b[i]=read(),c[i]=read();
		if(b[i]!=-1){
			v[b[i]]++;
		}
		if(c[i]!=-1)v[c[i]]++;
		mp[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			dfs(i,0,INF);
		}
	}
	int ans=0;
	for(auto x:s){
		ans+=mp[x];
	}

	return 0*printf("%d\n",n-ans);
}