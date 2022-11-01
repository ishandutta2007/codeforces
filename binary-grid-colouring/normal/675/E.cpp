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
typedef vector<int> vi;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson  l , mid , rt << 1  
#define rson  mid + 1 , r , rt << 1 | 1  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9+7;  
const ll mod = (1LL<<32);
const int N =1e5+7; 
const int M=100010;
const ll MAX=1e18;
//const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

ll dp[N],ans;
int maxn[N*4], a[N];
int n;

void pushup(int rt)
{
    if( a[maxn[rt<<1|1]] < a[maxn[rt<<1]]) 
	maxn[rt]=maxn[rt<<1];
    else
    maxn[rt]=maxn[rt<<1|1];

}

int query(int L,int R,int l,int r,int rt)
{
       if(L<=l && R>=r) return maxn[rt];
       int mid=(l+r)>>1, p=-1, q=-1;
       if(L<=mid) p=query(L,R,lson);
       if(R>mid)  q=query(L,R,rson);
       if(p==-1) return q;
       if(q==-1) return p;
       return  a[p]>a[q]?p:q;
}

void build(int l,int r,int rt)
{
     if(l==r)
     {
          maxn[rt]=l;
          return;
     }
     int mid=(l+r)>>1;
     build(lson); 
	 build(rson);
     pushup(rt);
}

void solve()
{
     dp[n] =0;
     int m=0;
     for(int i=n-1;i>=1;--i)
     {
           m=query(i+1,a[i],1,n,1);
           dp[i]=dp[m]-(a[i]-m)+(n-i);
           ans+=dp[i];
     }
}

int main()
{
      cin>>n;
      for(int i=1;i<n;i++){
      	 cin>>a[i];
	  } 
      a[n]=n;
      build(1,n,1);
      solve();
      cout<<ans;
}