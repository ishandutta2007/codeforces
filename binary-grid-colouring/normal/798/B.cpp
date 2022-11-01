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
string solve(string s, int k)
{
	 for (int i = 0; i < k; i++)
	 { 
	 	s += s[0]; 
		s.erase(s.begin());
	 } 
	 return s; 
} 
int main()
{
	//string s,t;
	//cin>>s;
	int n; 
	n=read();
	vector<string> a(n); 
	for (int i = 0; i < n; i++) 
	{ 
		cin>>a[i];
	} 
	int ans = INF; 
	for (int k = 0; k <= 50; k++)
	{ 
		string tmp = solve(a[0], k); 
		int x = k; 
		bool flag = true; 
		for (int i = 1; i < n; i++) 
		{ 
			bool fflag = false; 
			for (int j = 0; j <= 50; j++)
			{ 
				if (solve(a[i], j) == tmp)
				{ 
					x += j; 
					fflag = true; 
					break; 
				} 
			} 
			flag &= fflag; 
		} 
		if (flag)
		{ 
			ans = min(ans, x); 
		} 
	} 
	cout<<(ans < INF ? ans:-1)<<endl; 
	return 0;
}