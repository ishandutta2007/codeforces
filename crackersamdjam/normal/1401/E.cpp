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
const int MM = 1e6+5;

int n, m, inf = 1e6;
ll ans;
int bit[MM];
void update(int i, int v){
	for(i++; i < MM; i += i&-i)
		bit[i] += v;
}
int query(int i){
	int ret = 0;
	for(i++; i; i -= i&-i)
		ret += bit[i];
	return ret;
}

struct st{
	int op, x, y, l, r;
}; vector<st> q;

int main(){
	scan(n, m);
	for(int i = 0,y,l,r; i < n; i++){
		scan(y, l, r);
		q.push_back({1, l, y});
		q.push_back({-1, r, y});
	}
	q.push_back({1, 0, inf});
	q.push_back({1, 0, 0});

	for(int i = 0,x,l,r; i < m; i++){
		scan(x, l, r);
		q.push_back({0, x, -1, l, r});
	}
	q.push_back({0, 0, -1, 0, inf});
	q.push_back({0, inf, -1, 0, inf});

	sort(all(q), [](st &x, st &y){
		if(x.x != y.x)
			return x.x < y.x;
		return x.op > y.op; //insert, query, then delete
	});
	for(auto i: q){
		if(i.op == 0)
			ans += query(i.r) - query(i.l-1);
		else
			update(i.y, i.op);
	}
	print(ans-n-m-3);
}