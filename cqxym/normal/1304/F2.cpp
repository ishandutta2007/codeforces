#include <bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
 
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define low_bit(x) ((x)&(-(x)))
#define debug(x) cerr<<#x<<"="<<x<<"\n"
#define MIN(a,b,c) min(a,min(b,c))
#define MAX(a,b,c) max(a,max(b,c))
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
 
const int N = 1e4+10;
const int mod = 998244353;
const int inf = 1e9;
const double eps = 1e-16;
const double pi = acos(-1);
 
 
inline int read()
{
  int p=0; int f=1; char ch=getchar();
  while(ch<'0' || ch>'9'){if(ch=='-') f*=-1; ch=getchar();}
  while(ch>='0' && ch<='9'){p=p*10+ch-'0'; ch=getchar();}
  return p*f;
}
 
#define int long long
 
int n,m,k,a[51][40010],sum[51][40010]; int f[51][40010];
int pre[40010],suf[40010];
 
int rt[2],tot,lc[N<<3],rc[N<<3],c[N<<3];
void link(int &u,int L,int R,int k,int val)
{
  if(!u) u=++tot;
  if(L==R){c[u] = val; return ;}
  int mid = (L+R)>>1;
  if(k<=mid) link(lc[u],L,mid,k,val);
  else link(rc[u],mid+1,R,k,val);
  c[u] = max(c[lc[u]] , c[rc[u]]);
}
int qry(int u,int L,int R,int l,int r)
{
  if(L==l && R==r) return c[u];
  int mid = (L+R)>>1;
  if(r<=mid) return qry(lc[u],L,mid,l,r);
  else if(l>mid) return qry(rc[u],mid+1,R,l,r);
  else return max(qry(lc[u],L,mid,l,mid) , qry(rc[u],mid+1,R,mid+1,r));
}
 
signed main()
{
	n = read(); m = read(); k = read();
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++) a[i][j] = read();
		for(int j=1;j<=2*m;j++) sum[i][j] = a[i][j] + sum[i][j-1];
  }
  
  for(int i=1;i<=m;i++) f[1][i] = sum[1][i+k-1] - sum[1][i-1] + sum[2][i+k-1] - sum[2][i-1];
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<=m;j++) pre[j] = suf[j] = f[i-1][j];
    for(int j=1;j<=m;j++) pre[j] = max(pre[j] , pre[j-1]);
    for(int j=m;j>=1;j--) suf[j] = max(suf[j] , suf[j+1]);
    
    for(int j=1;j<=tot;j++) lc[j] = rc[j] = c[j] = 0; rt[0] = rt[1] = tot = 0;
    
    for(int j=1;j<=m;j++) link(rt[0],1,m,j,f[i-1][j] - sum[i][j+k-1]);
    for(int j=1;j<=m;j++) link(rt[1],1,m,j,f[i-1][j] + sum[i][j-1]);
    
    for(int j=1;j<=m;j++)
    {
    	if(j-k > 0) f[i][j] = max(f[i][j] , pre[j-k] + sum[i+1][j+k-1] - sum[i+1][j-1] + sum[i][j+k-1] - sum[i][j-1]);
    	if(j+k <= m) f[i][j] = max(f[i][j] , suf[j+k] + sum[i+1][j+k-1] - sum[i+1][j-1] + sum[i][j+k-1] - sum[i][j-1]);
			f[i][j] = max(f[i][j] , qry(rt[0],1,m,max(1ll,j-k+1),j) + sum[i+1][j+k-1] - sum[i+1][j-1] + sum[i][j+k-1] - sum[i][j-1] + sum[i][j-1]);
			f[i][j] = max(f[i][j] , qry(rt[1],1,m,j,min(m,j+k-1)) + sum[i+1][j+k-1] - sum[i+1][j-1] + sum[i][j+k-1] - sum[i][j-1] - sum[i][j+k-1]);
    }
  }
  int mx = 0;
  for(int i=1;i<=m;i++) mx = max(mx , f[n][i]);
  return printf("%lld\n",mx),0;
}