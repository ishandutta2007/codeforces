#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

// #ifndef ONLINE_JUDGE
// template<typename T>
// void pr(T a){std::cerr<<a<<std::endl;}
// template<typename T,typename... Args>
// void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
// #else
// template<typename... Args>
// void pr(Args... args){}
// #endif

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
const int MM = 5e5+5;

int n;
char s[MM];
ll ans;
vector<pii> st;
ll sum;
//stack sum

int main(){
	scan(n);
	scanf("%s", s+1);
	int l = 1;
	for(int i = 1; i <= n; i++){
		//with curent i as right endpoing
		if(s[i] == '1'){
			ll d = i-l+1;
			ans += d*(d+1)/2;

			ll num = 0;
			while(size(st) and st.back().first <= d){
				auto rm = st.back(); st.pop_back();
				sum -= rm.first*rm.second;
				num += rm.second;
			}
			st.emplace_back(d, num);
			sum += num*d;
			ans += sum;

			// pr("i", i, d, d*(d+1)/2, sum);
		}
		else{
			ll d = i-l;
			ll num = d;
			for(ll j = num; j >= 0; j--){
				sum += j;
				st.emplace_back(j, 1);
				// pr("emp", j);
			}

			ans += sum;

			l = i+1;
			// pr("i", l, sum);
		}

	}
	print(ans);
}