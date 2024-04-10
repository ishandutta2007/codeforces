//#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
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
#include <complex>
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
#define point complex<double>
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
ll gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	//string s,t;
	//cin>>s;
	//in;
	int n; 
	n=read();
	vector<int>a(n+1);
	for(int i=0;i<n;i++){
		a[i]=read();
	}
	int gg = gcd(a[0], a[1]); 
	for (int i = 2; i < n; i++)
	{ 
	 	gg = gcd(gg, a[i]); 
	} 
	if (gg > 1)
	{ 
	   puts("YES");
	   cout<<"0"<<endl; //WA
	}
	
   	else
	{ 
		vector<vector<int>> dp(n+1, vector<int>(2, INF)); 
	    if (a[0] % 2 == 0)
		{ 
			dp[0][1] = 0; 
		} 
		else 
		{ 
			dp[0][0]=0; 
		} 
		for (int i=1; i<n; i++) 
		{ 
			if (a[i]%2==0) 
			{ 
				dp[i][1]=min(dp[i - 1][1], dp[i - 1][0] + 2); 
			} 
			else
			{ 
				dp[i][1]=min(dp[i - 1][1]+2, dp[i - 1][0] + 1); 
				dp[i][0]=dp[i - 1][1]; 
			} 
		} 
		puts("YES");
		return 0*printf("%d\n",dp[n-1][1]);
	} 
	 
	return 0;
}