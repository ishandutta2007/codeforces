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
typedef long long ll;

int t, n, k;

int sum(ll v){
	int ret = 0;
	while(v){
		ret += v%10;
		v /= 10;
	}
	return ret;
}

int ssum(ll v){
	int ret = 0;
	for(ll i = v; i <= v+k; i++)
		ret += sum(i);
	return ret;
}

int main(){
	scan(t);
	while(t--){
		scan(n, k);
		ll ans = LLONG_MAX;
		for(int i = 0; i < 200; i++){
			int v = ssum(i);
			if(v == n){
				ans = i;
				break;
			}
		}

		for(int f = 0; f <= 9; f++){
			int sum = ssum(f);
			string out = to_string(f);
			while(sum < n){
				int add = min((n-sum+k)/(k+1), ((f+k > 9 and out.size() == 1) ? 8 : 9));
				out.push_back(add+'0');
				sum += add*(k+1);
			}
			reverse(all(out));
			if(sum == n)
				ans = min(ans, stoll(out));
		}
		if(ans == LLONG_MAX)
			ans = -1;
		print(ans);
	}
}