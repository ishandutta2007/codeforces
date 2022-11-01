#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
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
const ll MOD = 1e6 + 3;  
const ll mod = (1LL<<32);
const int N =110; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
char a[1010][6];
int q_mod(ll a,ll b)    
{  
    ll ans=1;  
    while(b>0)  
    {  
        if(b&1)    
            ans=(ans*a)%MOD;           
        a=(a*a)%MOD;  
        b>>=1;
    }  
    return ans;  
}  
int main()
{
  ll n, k;
  cin>>n>>k;
  if(n<=62&&k>1ll<<n)
  {
    puts("1 1"); 
	return 0;
  }
    ll num=0; 
	for(ll i=k-1;i;i>>=1)
	{
		num+=i/2;
	}	  
    ll b=1;
	ll a=q_mod(2,n);
    for(ll i=1;i<=k-1;i++)
	{
        ll tmp=(a-i+MOD)%MOD;
        b=b*tmp%MOD;
        if(!tmp)break;
    }
	ll ans=q_mod( q_mod(2,num), MOD-2 );
    a=q_mod(a,k-1);
    a=a*ans%MOD; 
	b=b*ans%MOD;
    b=(a-b+MOD)%MOD;
    printf("%I64d %I64d\n",b,a);
}