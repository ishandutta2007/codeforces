#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif


using namespace std;
using ll = long long;
const int MM = 1e5+5, SQ = 300, NN = 2e6+5;

int n, q, k, a[MM], cnt[NN];
ll ans[MM];

struct st{
	int l, r, id;
	bool operator<(const st &o) const{
		if(l/SQ != o.l/SQ)
			return l/SQ < o.l/SQ;
		return r < o.r;
	}
} b[MM];

ll sum;

int main(){
	scan(n, q, k);
	for(int i = 1; i <= n; i++){
		scan(a[i]);
		a[i] ^= a[i-1];
	}

	for(int i = 0; i < q; i++){
		scan(b[i].l, b[i].r);
		b[i].l--;
		b[i].id = i;
	}

	sort(b, b+q);
	int l = 0, r = 0;
	cnt[0] = 1;
	for(int i = 0; i < q; i++){
		while(l < b[i].l){
			cnt[a[l]]--;
			sum -= cnt[a[l]^k];
			l++;
		}
		while(l > b[i].l){
			l--;
			sum += cnt[a[l]^k];
			cnt[a[l]]++;
		}
		while(r < b[i].r){
			r++;
			sum += cnt[a[r]^k];
			cnt[a[r]]++;
		}
		while(r > b[i].r){
			cnt[a[r]]--;
			sum -= cnt[a[r]^k];
			r--;
		}
		// print(l, r, sum);
		ans[b[i].id] = sum;
	}

	for(int i = 0; i < q; i++)
		print(ans[i]);
}