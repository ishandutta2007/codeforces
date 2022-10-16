#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
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
using pii = array<int, 3>;
const int MM = 1e5+5;

ll ans = LLONG_MAX;
int n, k;
pii lx[MM], ly[MM];

int main(){
	scan(n, k);
	for(int i = 1,a,b,c,d; i <= n; i++){
		scan(a, b, c, d);
		lx[i] = ly[i] = {a+c, b+d, i};
	}
	sort(lx+1, lx+n+1, [](pii x, pii y){
		return x[0] < y[0];
	});
	sort(ly+1, ly+n+1, [](pii x, pii y){
		return x[1] < y[1];
	});

	for(int i = 0; i <= k; i++){
		for(int j = 0; j <= k; j++){
			for(int a = 0; a <= k; a++){
				for(int b = 0; b <= k; b++){
					set<pii> st;
					for(int t = 1; t <= i; t++)
						st.insert(lx[t]);
					for(int t = n; t > n-j; t--)
						st.insert(lx[t]);
					for(int t = 1; t <= a; t++)
						st.insert(ly[t]);
					for(int t = n; t > n-b; t--)
						st.insert(ly[t]);
					if(size(st) <= k){
						// pr(size(st), i+1, n-j, a+1, n-b, ",", lx[n-j][0], lx[i+1][0], ly[n-b][1], ly[a+1][1]);
						ans = min(ans, (ll)max(1, (lx[n-j][0]-lx[i+1][0]+1)/2)*max(1, (ly[n-b][1]-ly[a+1][1]+1)/2));
					}
				}
			}
		}
	}

	print(ans);
}