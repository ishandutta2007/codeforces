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
multiset<int>s;
int main()
{
	
    int n;
    n=read();
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    	s.insert(a[i]);
	}
	vector<vector<int>>V(n+1); 
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		u=read();
		v=read();
		V[u].push_back(v); 
		V[v].push_back(u);
	}
	int ans=9999999999;//max??WA ..fuck
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i];
		s.erase(s.find(a[i]));//erase
		for(auto v : V[i])
		{
			tmp = max(tmp, a[v] +1); 
			
			s.erase(s.find(a[v]));
		}
		if(!s.empty())
		{ 
			tmp = max(tmp,*s.rbegin()+2); 
		} 
		s.insert(a[i]);
		for(auto v: V[i])
		{
			s.insert(a[v]);
		}
		ans=min(tmp,ans);//min
	}
	cout<<ans<<endl;
	return 0;
}