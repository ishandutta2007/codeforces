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

int main(){
	scan(t);
	while(t--){
		scan(n);
		vector<int> v[2];
		for(int i = 1,a; i <= n+n; i++){
			scan(a);
			v[a%2].emplace_back(i);
		}
		if(int(v[0].size()) % 2 == 1){
			v[0].pop_back();
			v[1].pop_back();
		}
		else if(v[0].size()){
			v[0].pop_back();
			v[0].pop_back();
		}
		else{
			v[1].pop_back();
			v[1].pop_back();
		}
		while(v[0].size()){
			int a = v[0].back(); v[0].pop_back();
			int b = v[0].back(); v[0].pop_back();
			print(a, b);
		}
		swap(v[0], v[1]);
		while(v[0].size()){
			int a = v[0].back(); v[0].pop_back();
			int b = v[0].back(); v[0].pop_back();
			print(a, b);
		}
	}
}