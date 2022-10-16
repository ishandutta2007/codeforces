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
using ll = long long;

int t, n, m;
ll a[105];
string s;

int main(){
	scan(t);
	while(t--){
		scan(n, m);
		set<ll> st;
		ll sz = (1LL<<m)-n;
		for(int i = 0; i < n; i++){
			cin>>s;
			a[i] = stoll(s, 0, 2);
			st.insert(a[i]);
		}
		sort(a, a+n);
		ll ans = (sz-1)/2;
		// print(sz, ans);
		for(auto i: st){
			if(i <= ans)
				ans++;
		}
		// print(ans);
		// printf("ans ");
		for(int i = m-1; i >= 0; i--){
			if(ans&(1LL<<i))
				pc('1');
			else
				pc('0');
		}
		pc(10);
	}


	
	return 0;
}