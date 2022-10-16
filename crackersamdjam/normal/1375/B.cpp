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

int t, n, m, a[305][305], on[305][305];

int go(int i, int j){
	int cnt = 0;
	if(i > 1) cnt++;
	if(i < n) cnt++;
	if(j > 1) cnt++;
	if(j < m) cnt++;
	return cnt;
}

int main(){
	scan(t);
	while(t--){
		memset(on, 0, sizeof on);
		scan(n, m);
		bool no = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scan(a[i][j]);
				if(a[i][j] > go(i, j))
					no = 1;
			}
		}
		if(no){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= m; j++){
					printf("%d ", go(i, j));
				}
				pc(10);
			}
		}
	}
}