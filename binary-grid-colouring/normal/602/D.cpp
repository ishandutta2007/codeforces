#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 3e5+7; 
const int M=100010;
const int maxn=1e5+7; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int n,q;
int a[maxn],b[maxn];
pii p[maxn];
ll solve(int l,int r)
{
	ll ans=0;
	ll sum=0;
	int rear=0;
	for(int i=l;i<r;i++)
	{
		int num=1;
		while(rear && b[i] >= p[rear].first)
		{
			sum-=(1ll * p[rear].first * p[rear].second);
			num+=p[rear].second;
			rear--;	
		}
		p[++rear].first=b[i];
		p[rear].second=num;
	    sum+=(1ll*b[i]*num);
		ans+=sum;
	}
	return ans;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)b[i]=abs(a[i]-a[i+1]);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<solve(l,r)<<endl;
	}
	return 0;
}