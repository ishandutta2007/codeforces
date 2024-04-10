#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int t, n, a[105];

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 1; i <= n; i++){
			a[i] = i;
			printf("%d ", a[i]);
		}
		pc(10);
		// for(int i = 1; i <= n; i++){
		// 	for(int j = i; j <= n; j++){
		// 		int v = 0;
		// 		for(int k = i; k <= j; k++){
		// 			v |= a[k];
		// 		}
		// 		assert(v >= j-i+1);
		// 	}
		// }
	}
}