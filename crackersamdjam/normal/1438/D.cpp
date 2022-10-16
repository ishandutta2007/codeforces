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
const int MM = 1e5+5;

int n;
map<int, int> in;
set<int> st;
vector<array<int, 3>> out;
vector<array<int, 2>> ed;

int main(){
	scan(n);
	for(int i = 1,a; i <= n; i++){
		scan(a);
		if(in[a]){
			ed.push_back({in[a], i});
			in[a] = 0;
			st.erase(a);
		}
		else{
			in[a] = i;
			st.insert(a);
		}
	}
	while(size(st) >= 3){
		auto a = *st.begin();
		st.erase(a);
		auto b = *st.begin();
		st.erase(b);
		auto c = *st.begin();
		st.erase(c);

		out.push_back({in[a], in[b], in[c]});
		ed.push_back({in[a], in[b]});

		int d = a^b^c;

		if(in[d]){
			ed.push_back({in[d], in[c]});
			in[d] = 0;
			st.erase(d);
		}
		else{
			in[d] = in[c];
			st.insert(d);
		}
		in[a] = in[b] = in[c] = 0;
	}

	if(size(st) < 2){
		if(size(st)){
			int j = in[*st.begin()];
			for(auto i: ed)
				out.push_back({j, i[0], i[1]});
		}
		else if(size(ed)*2 == n){
			//everyone is paired up
			int j = ed.back()[0];
			ed.pop_back();
			for(auto i: ed)
				out.push_back({j, i[0], i[1]});
		}
		puts("YES");
		print(size(out));
		assert(size(out) <= n);
		for(auto i: out)
			print(i[0], i[1], i[2]);
	}
	else{
		puts("NO");
	}
}