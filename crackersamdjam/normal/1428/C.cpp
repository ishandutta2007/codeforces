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



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		vector<char> v;
		for(auto c: s){
			v.push_back(c);
			if(v.size() >= 2 and v[v.size()-2] == 'A' and v.back() == 'B'){
				v.pop_back();
				v.pop_back();
			}
		}
		vector<char> v2;
		for(auto c: v){
			v2.push_back(c);
			if(size(v2) >= 2 and v2[v2.size()-2] == 'B' and v2.back() == 'B'){
				v2.pop_back();
				v2.pop_back();
			}
		}
		cout<<v2.size()<<'\n';;
	}
}