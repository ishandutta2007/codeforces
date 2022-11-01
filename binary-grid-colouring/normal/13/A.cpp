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
#pragma GCC optimize ("O3")
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;
const int INF = 1e9+7;
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;
const ll mod = 1e9 + 7;
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
/*
ios::sync_with_stdio(0);
cin.tie(0);
*/
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int main()
{
    
    int n;
    n=read();
//    timer tim;
    int u = 0;
    int d = n - 2;
    for(int i=2;i<=n-1;i++)
    {
    	int t = n;
    	while(t)
    	{
    		u += t%i;
    		t/=i;
		}
	}
	int g=__gcd(u,d);
	printf("%d/%d\n",u/g,d/g);
	return 0;
}