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
const int MM = 1e5+5;

int t, n;
char a[MM], b[MM];

int main(){
	scan(t);
	while(t--){
		scan(n);
		scanf("%s %s", a, b);
		vector<int> va, vb;
		char last = a[0];
		for(int i = 1; i < n; i++){
			if(a[i] != last){
				last = a[i];
				va.emplace_back(i-1);
			}
		}
		last = b[0];
		for(int i = 1; i < n; i++){
			if(b[i] != last){
				last = b[i];
				vb.emplace_back(i-1);
			}
		}
		if(b[n-1] != a[n-1]){
			vb.emplace_back(n-1);
		}
		printf("%ld ", va.size() + vb.size());
		for(int i: va)
			printf("%d ", i+1);
		reverse(all(vb));
		for(int i: vb)
			printf("%d ", i+1);
		pc(10);
	}
}