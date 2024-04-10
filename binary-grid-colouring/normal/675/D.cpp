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
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e6 + 3;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
//const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
set<int> num;
map<int,int> Left,Right;
int n;
void init()
{
	num.clear();
	Left.clear();
	Right.clear();
}
int main()
{
	int v;
	cin>>n;
	init();
	cin>>v;
	num.insert(v);
	vector<int> ans;
	for(int i=0;i<n-1;i++)
	{
		cin>>v;
		set<int>::iterator it = num.upper_bound(v);
		if(it != num.end() && Left[*it] == 0)
		{
			ans.push_back(*it);
			Left[*it] = 1;
		}
		else {
			--it;
			ans.push_back(*it);
			Right[*it] = 1 ;
		}
			num.insert(v);
    }
	for(int i=0;i<ans.size()-1;i++)
	cout<<ans[i]<<" ";
	cout<<ans[ans.size()-1];
	
	
    return 0;
}