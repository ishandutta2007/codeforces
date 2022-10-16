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

int t, n, a[55][55];
char s[55][55];

int main(){
	scan(t);
	while(t--){
		scan(n);
		for(int i = 0; i < n; i++){
			scanf("%s", s[i]);
			for(int j = 0; j < n; j++)
				a[i][j] = 0;
		}
		bool b = 1;
		for(int i = n-1; i >= 0; i--){
			for(int j=  n-1; j >= 0; j--){
				if(s[i][j] == '1'){
					if(i == n-1 or j == n-1){
						a[i][j] = 1;
					}
					else{
						a[i][j] = a[i+1][j]|a[i][j+1];
					}
					if(!a[i][j])
						b = 0;
				}
			}
		}
		puts(b?"YES":"NO");
	}
	

	
	return 0;
}