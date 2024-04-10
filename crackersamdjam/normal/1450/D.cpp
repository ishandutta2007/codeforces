#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 3e5+5;

int t, n;

int main(){
	scan(t);
	while(t--){
		scan(n);
		vector<int> a(n+2), l(n+2), r(n+2);
		vector<vector<int>> rm(n+3);
		for(int i = 1; i <= n; i++)
			scan(a[i]);

		stack<int> st;
		for(int i = 1; i <= n+1; i++){
			while(size(st) and a[st.top()] > a[i]){
				r[st.top()] = i;
				st.pop();
			}
			st.emplace(i);
		}
		while(size(st))
			st.pop();
		
		//0 too
		for(int i = n+1; i >= 0; i--){
			while(size(st) and a[st.top()] > a[i]){
				l[st.top()] = i;
				st.pop();
			}
			st.emplace(i);
		}

		map<int, int> mp;
		for(int i = 1; i <= n; i++){
			mp[a[i]]++;
			int tt = (r[i]-i) + (i-l[i])-2;
			if(tt+1 <= n+2)
				rm[tt+1].emplace_back(a[i]);
			// pr(a[i], l[i], r[i], tt);
		}

		for(int k = 1; k <= n; k++){
			int ans = ((int)size(mp) == n-k+1 and (--mp.end())->first == n-k+1);
			pc('0'+ans);
			// pr("k", k, ans, size(mp), (--mp.end())->first, n-k+1);
			for(auto i: rm[k]){
				// pr("rm", i);
				mp[i]--;
				if(!mp[i]){
					mp.erase(i);
				}
			}

		}
		pc(10);
	}
}