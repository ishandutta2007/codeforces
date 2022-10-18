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
const int MM = 1e5+5;

int t, n, a;

int main(){
	scan(t);
	while(t--){
		vector<int> pos, neg;
		scan(n);
		while(n--){
			scan(a);
			pos.emplace_back(a);
			neg.emplace_back(a);
		}
		sort(all(pos));
		reverse(all(pos));
		sort(all(neg));
		ll ans = LLONG_MIN;
		ans = max(ans, (ll)pos[0]*pos[1]*pos[2]*pos[3]*pos[4]);
		ans = max(ans, (ll)pos[0]*pos[1]*pos[2]*pos[3]*neg[0]);
		ans = max(ans, (ll)pos[0]*pos[1]*pos[2]*neg[0]*neg[1]);
		ans = max(ans, (ll)pos[0]*pos[1]*neg[0]*neg[1]*neg[2]);
		ans = max(ans, (ll)pos[0]*neg[0]*neg[1]*neg[2]*neg[3]);
		print(ans);
	}
}