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
const ll INF = 1e18; 
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
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int a[123456];
int tmp[123456];
ll dp[23][123456];
int Left,Right;
ll res;
ll change(int l, int r)
{
	while(Left<l)
	{
		--tmp[a[Left]];
		res-=tmp[a[Left]];
		++Left;
	}
	while(Left>l)
	{
		--Left;
		res+=tmp[a[Left]];
		++tmp[a[Left]];
	}
	while(Right<r)
	{
		res+=tmp[a[Right]];
		++tmp[a[Right]];
		++Right;
	}
	while (Right>r)
	{
		--Right;
		--tmp[a[Right]];
		res-=tmp[a[Right]];
	}
//	cout<<"res="<<endl;
	return res;
}
void solve(int l, int r, int _left, int _right,int val)
{
	if (l > r)return;
	int mid=(l+r)>>1;
	int Mid=mid;
	dp[val+1][mid]=dp[val][mid];
	for (int i=_left;i<=_right&&i<mid;i++)
	{
		ll Max=change(i, mid)+dp[val][i];
		if (dp[val+1][mid]>Max)
		{
			dp[val+1][mid]=Max;
			Mid=i;
//			cout<<"Max="<<Max<<endl;
//			cout<<"Mid="<<Mid<<endl; 
		}
	}
	solve(l,mid-1,_left,Mid,val);
	solve(mid+1,r,Mid,_right,val);
}
/*
10 2
1 2 1 2 1 2 1 2 1 2
8
*/
int n,m;
int main()
{
	//timer tim;
	n=read(),m=read();
	for(int i=0;i<n;i++){
		a[i]=read();
	}
	dp[0][0] = 0;
	for (int i=1;i<=n;i++){
		dp[0][i]=INF;
	}
	//cout<<"finish"<<endl;
	for (int i=0;i<m;i++){
		//cout<<"debug"<<endl;
		solve(0,n,0,n,i);
	}
	cout<<dp[m][n]<<endl;
	return 0;
}