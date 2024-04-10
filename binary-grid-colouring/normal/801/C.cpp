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
map<int,int>mp;
int a[100010],b[100010];
int n,p;
bool check(double x)
{
	double tmp=x*p;
	for(int i=0;i<n;i++)
	{
		if( b[i] + tmp < a[i]*x )return false ;
		if( b[i] >= a[i]*x ) continue;
		tmp = tmp- a[i]*x + b[i];
	}
	return true;
	
}
int main()
{
	n=read(),p=read();
	for(int i=0;i<n;i++){
		a[i]=read(),b[i]=read();
	}
	double l=0,r=1e15;
	for(int i=0;i<200;i++){
		double mid=(l+r)/2.0;
		if(check(mid))l=mid;
		else r=mid;
	}
	if(l>=1e14)cout<<"-1"<<endl;
	else printf("%.10f\n",l);
	return 0;
}