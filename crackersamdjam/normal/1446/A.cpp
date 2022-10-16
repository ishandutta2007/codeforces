#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int t, n;
ll w, a[MM];

int main(){
	scan(t);
	while(t--){
		scan(n, w);
		ll sum = 0;
		for(int i = 0; i < n; i++){
			scan(a[i]);
			if(a[i] <= w)
				sum += a[i];
		}

		for(int i = 0; i < n; i++){
			if(a[i] >= (w+1)/2 and a[i] <= w){
				print(1);
				print(i+1);
				goto out;
			}
		}
		if(sum < (w+1)/2){
			print(-1);
		}
		else{
			vector<int> v;
			sum = 0;
			for(int i = 0; i < n; i++){
				if(sum+a[i] > w)
					continue;

				sum += a[i];
				v.emplace_back(i+1);
				if(sum >= (w+1)/2)
					break;
			}
			print(size(v));
			for(int i: v)
				printf("%d ", i);
			pc(10);
		}

		out:;
	}
}