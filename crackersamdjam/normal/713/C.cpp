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

struct sfun{
	priority_queue<ll> q;
	ll m = 0, b = 0;
	sfun(ll _m, ll _b, vector<ll> v){
		m = _m, b = _b;
		for(const auto &x: v)
			q.emplace(x);
	}
	void merge(sfun o){
		if(size(o.q) > size(q))
			swap(o, *this);
		m += o.m, b += o.b;
		while(size(o.q)){
			q.push(o.q.top());
			o.q.pop();
		}
	}
};

int main(){
	int n, a;
	sfun t(0, 0, {});
	scan(n);
	for(int i = 0; i < n; i++){
		scan(a);
		a -= i;
		t.merge(sfun(-1, a, {a, a}));
		t.q.pop();
	}
	ll ans = t.b;
	while(size(t.q)){
		ans -= t.q.top();
		t.q.pop();
	}
	print(ans);
}