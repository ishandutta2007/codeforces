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

int t, n;
int dp[100];

int main(){
//	for(int i = 2; i < 100; i++){
//		dp[i] |= !dp[i-1];
//		for(int j = 3; j <= i; j += 2){
//			if(i%j == 0){
//				dp[i] |= !dp[i/j];
//			}
//		}
//	}
	
	scan(t);
	while(t--){
		scan(n);
//		cout<<(dp[n] ? "Ashishgup" : "FastestFinger")<<", ";
		if(n == 1 or n == 4){
			puts("FastestFinger");
			continue;
		}
		if(n == 2){
			puts("Ashishgup");
			continue;
		}
		
		if(n%2 == 1){
			puts("Ashishgup");
			continue;
		}
		
		n /= 2;
		if(n%2 == 0){
			// 4
			puts(__builtin_popcount(n) == 1? "FastestFinger" : "Ashishgup");
		}
		else{
			//2
			int ok = 0;
			for(long long i = 2; i*i <= n; i++){
				if(n%i == 0)
					ok = 1;
			}
			puts(ok ? "Ashishgup" : "FastestFinger");
		}
	}
}