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

struct Query
{
	int b, id, ans;
	bool operator<(const Query &rhs) const { return b < rhs.b; }
	bool operator<(const int &rhs) const { return b < rhs; }
};

struct Interval
{
	int l, r, delta, ans;
	Interval(int l, int r, int delta = 0, int ans = 0) : l(l), r(r), delta(delta), ans(ans) {}
};

const int MAGIC = 2000;
int n,k;
pair<int, int> p[200000];
Query q[200000];
vector<Interval> v;
int ans[200000];

void rebuild()
{
	for (int i = 0; i < v.size(); ++i)
		for (int j = v[i].l; j < v[i].r; ++j)
			q[j].ans += v[i].ans, q[j].b += v[i].delta;
	sort(q, q + k);
	v.clear();
	v.push_back(Interval(0, k));
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &p[i].second, &p[i].first), p[i].first *= -1;
	sort(p, p + n);
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", &q[i].b), q[i].id = i;
	rebuild();
	for (int i = 0; i < n; ++i)
	{
		int c = p[i].second;
		for (int j = 0, m = v.size(); j < m; ++j)
		{
			if (q[v[j].l].b + v[j].delta >= c)
				v[j].delta -= c, ++v[j].ans;
			else if (q[v[j].r - 1].b + v[j].delta >= c)
			{
				int pos = lower_bound(q + v[j].l, q + v[j].r, c - v[j].delta) - q;
				v.push_back(Interval(pos, v[j].r, v[j].delta - c, v[j].ans + 1));
				v[j].r = pos;
			}
		}
		if (v.size() > MAGIC)
			rebuild();
	}
	rebuild();
	for (int i = 0; i < k; ++i)
		ans[q[i].id] = q[i].ans;
	for (int i = 0; i < k; ++i)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}