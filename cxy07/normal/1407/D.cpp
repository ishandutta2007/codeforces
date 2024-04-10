//Code By CXY07
#include<bits/stdc++.h>
using namespace std;
 
//#define FILE
//#define int long long
//#define ull unsigned long long
#define LL long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define scd second
#define inv(x) qpow((x),mod - 2)
#define lowbit(x) ((x) & (-(x)))
 
const int MAXN = 3e5 + 10;
const int INF = 2e9;
const double PI = acos(-1);
const double eps = 1e-6;
//const int mod = 1e9 + 7;
//const int mod = 998244353;
//const int G = 3;
//const int base = 131;
 
struct SMT {
	int seg[MAXN << 2];
	void Init(int x,int l,int r) {
		seg[x] = INF;
		if(l == r) return;
		int mid = (l + r) >> 1;
		Init(x << 1,l,mid);
		Init(x << 1 | 1,mid + 1,r);
	}
	void Update(int x,int l,int r,int pos,int v) {
		if(l == r) {
			seg[x] = v;
			return;
		}
		int mid = (l + r) >> 1;
		if(pos <= mid) Update(x << 1,l,mid,pos,v);
		else Update(x << 1 | 1,mid + 1,r,pos,v);
		seg[x] = min(seg[x << 1],seg[x << 1 | 1]);
	}
	int Query(int x,int l,int r,int L,int R) {
		if(L <= l && r <= R) return seg[x];
		int mid = (l + r) >> 1,res = INF;
		if(L <= mid) res = min(res,Query(x << 1,l,mid,L,R));
		if(R > mid) res = min(res,Query(x << 1 | 1,mid + 1,r,L,R));
		return res;
	}
};
 
int n,m;
int a[MAXN],dp[MAXN];
 
struct Stack {
	int st[MAXN],top,cmp;
	void Init(int c) {
		top = 0;
		cmp = c;
	}
	void Push(int x) {
		int res = 0;
		while(top && ::a[st[top]] * cmp <= ::a[x] * cmp) {
			if(!res) dp[x] = min(dp[x],dp[st[top]] + 1);
			if(a[st[top]] == a[x]) res = 1;
			top--;
		}
		if(top && !res) dp[x] = min(dp[x],dp[st[top]] + 1);
		st[++top] = x;
	}
	void Print() {
		for(int i = 1;i <= top; ++i)
			cout << a[st[i]] << ' ';
		cout << endl;
	}
} Max,Min;
 
template<typename T> inline void read(T &a) {
	a = 0; char c = getchar(); int f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
	a *= f;
}
 
signed main () {
#ifdef FILE
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	read(n);
	for(int i = 1;i <= n; ++i) read(a[i]);
	Max.Init(1),Min.Init(-1);
	memset(dp,0x3f,sizeof dp);
	dp[1] = 0;
	Max.Push(1); Min.Push(1);
	for(int i = 2;i <= n; ++i) {
		Max.Push(i);
		Min.Push(i);
	} 
	printf("%d\n",dp[n]);
	return 0;
}