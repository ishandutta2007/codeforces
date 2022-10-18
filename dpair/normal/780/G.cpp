/*
	author: DPair
	language: C++11

	description:
	
*/
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
namespace MyMinMax{
	template <typename T>
	inline T mn(T x, T y) {return x < y ? x : y;}
	template <typename T>
	inline T mx(T x, T y) {return x > y ? x : y;}
	template <typename T>
	inline void chmin(T &x, T y) {(x > y) && (x = y);}
	template <typename T>
	inline void chmax(T &x, T y) {(x < y) && (x = y);}
}
using namespace MyMinMax;
namespace IO{
	#define getcha() (SS == TT && (TT = (SS = BB) + fread(BB, 1, 1 << 23, stdin), SS == TT) ? EOF : *SS++)
	char BB[1 << 23], *SS = BB, *TT = BB;
	template <typename T>
	inline void read(T &x){
		x = 0;int fu = 1;
		char c = getcha();
		while(c > 57 || c < 48){
			if(c == 45) fu = -1;
			c = getcha();
		}
		while(c <= 57 && c >= 48){
			x = x * 10 + c - 48;
			c = getcha();
		}
		x *= fu;
	}
	template <typename T, typename ...Args>
	inline void read(T &x, Args &...args){
		read(x);read(args...);
	}
	char out[1 << 22], *Out = out;
	#define flush() fwrite(out, 1, Out - out, stdout)
	inline void putcha(char x) {*Out++ = x;if(Out - out >= (1 << 22)) flush(), Out = out;}
	template <typename T>
	inline void fprint(T x){
		if(x < 0) putcha(45), x = -x;
		if(x > 9) fprint(x / 10);
		putcha(x % 10 + 48);
	}
	template <typename T>
	inline void print(T x){fprint(x);putcha(10);}
	inline void print(const char *ch){while(*ch != '\0') putcha(*(ch ++));}
	inline void put(const char *ch){while(*ch != '\0') putcha(*(ch ++));putcha(10);}
	template <typename T, typename ...Args>
	inline void print(T x, Args ...args){fprint(x);putcha(32);print(args...);}
	template <typename T>
	inline void sprint(T x){fprint(x);putcha(32);}
	template <typename T, typename ...Args>
	inline void sprint(T x, Args ...args){fprint(x);putcha(32);sprint(args...);}
	class AutoFlush{
		public:
			~AutoFlush(){flush();}
	}__AutoFlush;
} // namespace IO
using namespace IO;
typedef long long LL;
const LL MOD = 1e9+7;
int h, w, n;
#define MAXN 100005
int L[MAXN], R[MAXN];
map <int, int> hei;//index, idresult
struct board{
	int x, y;//xyy
	//
	// set lower_bound
	inline bool operator < (const board &tmp) const{return y > tmp.y;}
};
int it[MAXN << 2];
set <int> s[MAXN << 2];
vector <board> vec[MAXN << 2];
#define LSON rt << 1, l, mid
#define RSON rt << 1 | 1, mid + 1, r
void modify(int rt, int l, int r, int x, int y, board z){
	if(x <= l && r <= y) return vec[rt].push_back(z);
	int mid = (l + r) >> 1;
	if(x <= mid) modify(LSON, x, y, z);
	if(y > mid) modify(RSON, x, y, z);
}
void build(int rt, int l, int r){
	it[rt] = -1;
	sort(vec[rt].begin(), vec[rt].end());
	if(l == r) return ;
	int mid = (l + r) >> 1;
	build(LSON);build(RSON);
}
int query(int rt, int l, int r, int x, int y){// y 
	while(it[rt] + 1 < vec[rt].size() && vec[rt][it[rt] + 1].y >= y) s[rt].emplace(vec[rt][++ it[rt]].x);
	auto tt = s[rt].lower_bound(y);
	int ret = (tt == s[rt].begin())? 0 : *(-- tt);
	if(l == r) return ret;
	int mid = (l + r) >> 1;
	if(x <= mid) return mx(query(LSON, x, y), ret);
	else return mx(query(RSON, x, y), ret);
}
LL val[MAXN];
typedef pair <int, int> pi;
pi stk[MAXN];
int tp;
int main(){
	read(h, w, n);
	for (int i = 1;i <= n;++ i){
		board x;read(x.x);
		read(L[i]);read(R[i]);
		read(x.y);x.y += x.x;
		hei[x.x] = i;modify(1, 1, w, L[i], R[i], x);
	}
	hei[0] = n + 1;
	build(1, 1, w);
	for (int i = 1;i <= w;++ i){
		int res = query(1, 1, w, i, h + 1);
		val[hei[res]] ++;
	}
	tp = -1;
	for (auto i = hei.begin();i != hei.end();++ i) stk[++ tp] = *i;
	while(tp){
		pi x = stk[tp --];
		int id = x.second, pos = x.first;
		if(!val[id]) continue;
		LL num = val[id];
		if(L[id] == 1) {
			int res = query(1, 1, w, R[id] + 1, pos);
			int tar = hei[res];
			val[tar] = (val[tar] + (num << 1)) % MOD;
		}
		else if(R[id] == w){
			int res = query(1, 1, w, L[id] - 1, pos);
			int tar = hei[res];
			val[tar] = (val[tar] + (num << 1)) % MOD;
		}
		else{
			int res = query(1, 1, w, R[id] + 1, pos);
			int tar = hei[res];
			val[tar] = (val[tar] + num) % MOD;
			res = query(1, 1, w, L[id] - 1, pos);
			tar = hei[res];
			val[tar] = (val[tar] + num) % MOD;
		}
	}
	print(val[n + 1]);
}