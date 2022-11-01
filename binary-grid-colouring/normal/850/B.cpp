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
const int N =2000000; 
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
int a[1234567];
ll ans = 0;
ll sum[2000100];
ll cnt[2000100];
int main()
{
	//in;
    //timer tim;
    int n,x,y;
    n=read(),x=read(),y=read();
    ans = 1000000000000000000;

	for(int i=1;i<=n;i++)
	{
		int t;
		t=read();
		sum[t]+=t;
		cnt[t]++;
	}

	for(int i=2;i<=N;i++)
	{
		sum[i]+=sum[i-1];
		cnt[i]+=cnt[i-1];
	}
	ll index;
	index = x / y;
	for(int i=2;i<=1000000;i++)
	{
		ll tmp=0;
		for(int j = i;j <= i + 1000000;j+=i)
		{
			if(j - index > j - i)
			{
				tmp+=1LL * ((cnt[j]-cnt[j -index - 1]) * j - (sum[j] - sum[j-index-1])) * y;
				tmp+=1LL * (cnt[j - index - 1] - cnt[j - i]) * x;
			}
			else tmp += 1LL * ((cnt[j] - cnt[j-i])*j-( sum[j] - sum[j-i])) * y;
		}
		ans=min(ans,tmp);
	}
	printf("%lld\n",ans);
	return 0;
}