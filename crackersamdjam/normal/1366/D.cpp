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
const int MM = 5e5+5, MN = 1e7+5;

int n, a[MM], b[MM];
int f[MN], s[MN], np[MN];

int main(){
	for(int i = 2; i < MN; i++){
		if(np[i])
			continue;
		for(int j = i+i; j < MN; j += i){
			np[j] = 1;
			if(!f[j]){
				f[j] = 1;
				for(int t = j; t%i == 0; t /= i)
					f[j] *= i;
				s[j] = j/f[j];
				
				if(s[j] == 1){
					f[j] = s[j] = 0;
					//nope
				}
			}
		}
	}
	for(int i = 2; i < MN; i++){
		if(!f[i])
			f[i] = s[i] = -1;
	}

	scan(n);
	for(int i = 0, v; i < n; i++){
		scan(v);
		a[i] = f[v];
		b[i] = s[v];
	}
	for(int i = 0; i < n; i++)
		printf("%d ", a[i]);
	pc(10);
	for(int i = 0; i < n; i++)
		printf("%d ", b[i]);
	pc(10);
	
}