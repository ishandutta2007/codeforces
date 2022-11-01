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
//const ll mod = (1LL<<32);
//const int N =2000000; 
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
int N;
int A[1100010],B[1100010];
int inv2=500000004;
void fwt(int *a)
{
      int i,j,k,l,t,x,y;
      for (i=1;i<N;i<<=1)
      {
      	for (j=0,l=N/(i<<1);j<N;j+=i<<1)
      	{
      		for (k=0,l=0;k<i;++k,l+=t)
          	{
              	x=a[j+k]; 
				y=a[j+k+i];
              	a[j+k]=(x+y)%MOD; 
				a[j+k+i]=(x-y+MOD)%MOD;
          	}
		}
	  }
         
}
void wfwt(int *a)
{
    int i,j,k,l,t,x,y;
    for (i=1;i<N;i<<=1)
    {
      	for (j=0,l=N/(i<<1);j<N;j+=i<<1)
      	{
      		for (k=0,l=0;k<i;++k,l+=t)
          	{
              x=a[j+k]; 
			  y=a[j+k+i];
              a[j+k]=1ll*(x+y)*inv2%MOD; 
			  a[j+k+i]=1ll*(x-y+MOD)*inv2%MOD;
          	}
		}
          
	}     
}
int solve(int x)
{
	int res=0;
	while(x)
	{
		res+=(x&1);
		x>>=1;
	}
	return res;
}
int qpower(int x,int y)
{
		int res=1;
		while(y)
		{
			if (y&1) res=1LL * res * x % MOD;
			x=1LL * x * x % MOD; 
			y>>=1;
		}
		return res;
}
int ans = 0;
char s[1100010];
int main()
{
	//in;
    //timer tim;
    int n;
    n=read();
    scanf("%s",s);
	for (int i=0;i<(1<<n);i++) 
	{
		A[i]=s[i]-'0';
	}
	for (int i=0;i<(1<<n);i++) 
	{
		B[i]=1-A[i];
	}
	N=1<<n;
	fwt(A); 
	fwt(B);
	for (int i=0;i<(1<<n);i++) 
	{
		A[i]=1LL * A[i] * B[i] % MOD;
	}
	wfwt(A); 
	for (int i=0;i<(1<<n);i++)
	{
		ans += 3LL * A[i] * qpower(2,solve(i)) % MOD;
		ans%=MOD;
	 } 
	printf("%d\n",ans);	
	return 0;
}