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
const int MM = 1005;

int n, a[MM];
vector<pair<int, int>> out;

int main(){
	scan(n);
	for(int i = 1; i <= n; i++)
		scan(a[i]);
	for(int i = n; i; i--){
		vector<pair<int, int>> v;
		for(int j = 1; j < i; j++){
			if(a[j] > a[i]){
				v.emplace_back(a[j], j);
			}
		}
		sort(all(v));
		for(auto j: v)
			out.emplace_back(j.second, i);
	}
	print(out.size());
	for(auto i: out)
		print(i.first, i.second);
}