/*
	author: DPair
	language: C++

	description:
	wolieno prido, sasdieno tamaxi.
	ekuso, blue eyes whito doragon!
	
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x){
	x = 0;int fu = 1;
	char c = getchar();
	while(c > 57 || c < 48){
		if(c == 45) fu = -1;
		c = getchar();
	}
	while(c <= 57 && c >= 48){
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	x *= fu;
}
template <typename T>
inline void fprint(T x){
	if(x < 0) putchar(45), x = -x;
	if(x > 9) fprint(x / 10);
	putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
	fprint(x);putchar(ch);
}
template <typename T, typename ...Args>
inline void read(T &x, Args &...args){
	read(x);read(args...);
}
typedef long long LL;

set <LL> s;

inline bool check(LL x){
	LL sq = sqrt(x);
	return sq * sq == x;
}
LL t[2000005];
int tot;
inline void init(){
	for (LL i = 2;i <= 1e6;++ i){
		LL num = i * i;
		while(num <= 1e18 / i){
			num *= i;
			if(!check(num)) s.insert(num);
		}
	}
	for (auto it : s) t[++ tot] = it;
}

inline LL query(LL L, LL R){
	LL l = 1, r = 1e9, res1 = 1e9, res2 = 1e9;
	while(l <= r){
		LL mid = (l + r) >> 1;
		if(mid * mid >= L) res1 = mid, r = mid - 1;
		else l = mid + 1;
	}
	l = 1, r = 1e9;
	while(l <= r){
		LL mid = (l + r) >> 1;
		if(mid * mid <= R) res2 = mid, l = mid + 1;
		else r = mid - 1;
	}
	return res2 - res1 + 1;
}

int main(){
	init();
	int q;read(q);
	while(q --){
		LL l, r;read(l, r);
		int L = lower_bound(t + 1, t + tot + 1, l) - t;
		int R = upper_bound(t + 1, t + tot + 1, r) - t - 1;
		fprint(R - L + 1 + query(l, r), 10);
	}
}