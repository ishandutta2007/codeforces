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
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a && !b)return -1;
    if(!b)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}

ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
  
  int n, m;
  n=read(),m=read();
  vector<int> a(m+1);
  vector<vector<int>> b(m+1);
  for (int i = 0; i < n; i++)
  {
    int t;
    t=read();
    a[t]++;
  }
  for (int i = 1; i < m; i++)
  {
    if (a[i]==0)
	{
      b[gcd(i, m)].push_back(i);
    }
  }
  /*
  cout<<"----------------------"<<endl;
  for(int i=1;i<m;i++){
  	cout<<i<<" "<<" "; 
  	for(int j=0;j<b[i].size();j++){
  		cout<<b[i][j]<<" ";
	  }
	  cout<<endl;
  }
  cout<<"----------------------"<<endl;
  */
  vector<vector<int>> g(m+1);
  for (int i = 1; i < m; i++)
  {
    if (!b[i].empty())
	{
      for (int j = i + i; j < m; j += i) 
	  {
        if (!b[j].empty())
		{
          g[i].push_back(j);
        }
      }
    }
  }
  /*
  for(int i=1;i<m;i++){
  	cout<<i<<" "<<" "; 
  	for(int j=0;j<g[i].size();j++){
  		cout<<g[i][j]<<" ";
	  }
	  cout<<endl;
  }
  cout<<"----------------------"<<endl;
  */
  vector<int> dp(m+1);
  vector<int> pre(m+1);
  int p = m - 1;
  for (int i = m - 1; i >= 1; i--)
  {
     dp[i] = b[i].size();
     for (auto v : g[i])
	 {
	//   cout<<"i="<<i<<" "<<"v="<<v<<endl;
       if (dp[v] + b[i].size() > dp[i])
	   {
         dp[i] = dp[v] + b[i].size();
         pre[i] = v;
       }
     }
    
     if (dp[i] > dp[p])
	 {
       p = i;
     }
  }
  
  vector<int> ans;
  for (int i = p; i; i = pre[i])
  {
    for (auto x : b[i]) {
      ans.push_back(x);
     // cout<<"x="<<x<<" ";
    }
  }
 // cout<<endl;
  if (!ans.empty())
  {
    ll now = ans[0];
    for (int i = 1; i < ans.size(); i++)
	{
      ll x = 0, y = 0;
      int g = exgcd(now, m, x, y);
      x *= (ans[i] / g);
      x = (x % m + m) % m;
      ans[i] = x; // 
      now = now * x % m;
    }
  }
  
  if (!a[0])
  {
    ans.push_back(0);//hack
  }
  
  printf("%d\n",ans.size());
  for (auto x : ans) {
    printf("%d ",x);
  }
  return 0;
}