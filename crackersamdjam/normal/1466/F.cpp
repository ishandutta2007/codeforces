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
const ll mod = 1e9+7;
const int MM = 5e5+5;

int n, m;
ll ans = 1;
vector<int> out;
int par[MM], f[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	scan(n, m);
	for(int i = 1; i <= m; i++){
		par[i] = i;
	}

	for(int i = 1,k,a,b; i <= n; i++){
		scan(k);
		if(k == 1){
			scan(a);
			a = find(a);
			if(f[a]) continue;

			f[a] = 1;

			ans = ans*2%mod;
			out.emplace_back(i);
		}
		else{
			assert(k == 2);
			scan(a, b);
			a = find(a), b = find(b);
			if(a == b or (f[a] and f[b])){
				continue;
			}
			par[b] = a;
			f[a] |= f[b];

			ans = ans*2%mod;
			out.emplace_back(i);
		}
	}
	print(ans, size(out));
	for(int i: out)
		printf("%d ", i);
}