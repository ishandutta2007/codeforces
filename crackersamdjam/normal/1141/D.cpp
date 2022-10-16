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
const int MM = 150005;

vector<int> in[30], q, qq;
int n, ans;
string s, t;
vector<pair<int, int>> out;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>s>>t;
	for(int i = 0; i < n; i++){
		auto c = s[i];
		if(c == '?'){
			q.emplace_back(i);
		}
		else
			in[c-'a'].emplace_back(i);
	}
	for(int i = 0; i < n; i++){
		auto c = t[i];
		if(c == '?')
			qq.emplace_back(i);
		else{
			c -= 'a';
			if(in[c].size()){
				out.emplace_back(in[c].back(), i);
				in[c].pop_back();
			}
			else if(size(q)){
				out.emplace_back(q.back(), i);
				q.pop_back();
			}
		}
	}

	for(int i = 0; i < 30; i++){
		while(size(in[i]) and size(qq)){
			out.emplace_back(in[i].back(), qq.back());
			in[i].pop_back();
			qq.pop_back();
		}
	}

	while(size(q) and size(qq)){
		out.emplace_back(q.back(), qq.back());
		q.pop_back();
		qq.pop_back();
	}

	print(size(out));
	for(auto i: out)
		print(i.first+1, 1+i.second);
}