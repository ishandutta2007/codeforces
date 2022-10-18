#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, q;
ll bit[MM], sa, sb;

void up(int i, ll v){
	for(; i < MM; i += i&-i)
		bit[i] += v;
}

ll qu(int i){
	ll ret = 0;
	for(; i; i -= i&-i)
		ret += bit[i];
	return ret;
}
void adj(int i, ll m){
	if(i == 1 or i > n)
		return;
	ll f = qu(i-1), s = qu(i);
	if(f < s)
		sa += m*(s-f);
	else
		sb += m*(f-s);
}

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		ll a; scan(a);
		up(i, a);
		up(i+1, -a);
		adj(i, 1);
	}
	{
		ll a = qu(1);
		ll aa = a+sa;
		ll b = qu(n)-aa;
		ll bb = b+sb;
		ll dif = (aa-bb)/2;
		aa -= dif;
		bb += dif;
		print(max(aa, bb));
	}
	scan(q);
	while(q--){
		int l, r; ll v;
		scan(l, r, v);
		adj(r+1, -1);
		adj(l, -1);
		up(l, v);
		up(r+1, -v);
		adj(r+1, 1);
		adj(l, 1);

		ll a = qu(1);
		ll aa = a+sa;
		ll b = qu(n)-aa;
		ll bb = b+sb;
		ll dif = (aa-bb)/2;
		aa -= dif;
		bb += dif;
		print(max(aa, bb));
	}
}