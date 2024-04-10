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

int n, in;
vector<pair<int, int>> v;
set<pair<int, int>> st;

int main(){
	scan(n);
	if(n == 2){
		cout<<"18\n0 0\n"
			  "-1 0\n"
			  "1 0\n"
			  "0 -1\n"
			  "0 1\n"
			  "1 1\n"
			  "-2 0\n"
			  "-3 0\n"
			  "-3 -1\n"
			  "-3 -2\n"
			  "-3 -3\n"
			  "-2 -3\n"
			  "-1 -3\n"
			  "0 -3\n"
			  "0 -2\n"
			  "-3 -4\n"
			  "-4 -3\n"
	 "-4 -4";
		return 0;
	}
	
	in = n;
	n--;
	int i = 0;
	v.emplace_back(i, i);
	v.emplace_back(i-1, i);
	v.emplace_back(i+1, i);
	v.emplace_back(i, i-1);
	v.emplace_back(i, i+1);
	v.emplace_back(i-1, i+1);
	v.emplace_back(i+1, i-1);
	i++;
	
	if(n%3 == 1){
		n -= 2;
		v.emplace_back(-2, 0);
		v.emplace_back(-3, 0);
		v.emplace_back(-3, -1);
		v.emplace_back(-3, -2);
		v.emplace_back(-3, -3);
		v.emplace_back(-2, -3);
		v.emplace_back(-1, -3);
		v.emplace_back(0, -3);
		v.emplace_back(0, -2);
		
		v.emplace_back(-1, -1);
		
//		v.emplace_back(-3, -4);
//		v.emplace_back(-4, -3);
//		v.emplace_back(-4, -4);
	}
	
	while(n >= 3){
		n -= 3;
		v.emplace_back(i, i);
		v.emplace_back(i+1, i);
		v.emplace_back(i+1, i-1);
		v.emplace_back(i, i+1);
		v.emplace_back(i-1, i+1);
		i++;
	}
	if(n >= 2){
		n -= 2;
		//ending one
		v.emplace_back(i, i);
		v.emplace_back(i-1, i+1);
		v.emplace_back(i-1, i+2);
		v.emplace_back(i, i+2);
		v.emplace_back(i+1, i+2);
		v.emplace_back(i+2, i+2);
		v.emplace_back(i+2, i+1);
		v.emplace_back(i+2, i);
		v.emplace_back(i+2, i-1);
		v.emplace_back(i+1, i-1);
	}
	print(v.size());
	for(auto i: v)
		print(i.first, i.second);
	
	return 0;
	
	bool ff = 0;
	for(auto i: v){
		assert(!st.count(i));
		st.insert(i);
		if(i.first == 0 and i.second == 0)
			ff = 1;
	}
	int cnt = 0;
	cout<<flush;
	for(auto i: v){
		int c = st.count({i.first, i.second-1}) + st.count({i.first, i.second+1}) + st.count({i.first+1, i.second}) + st.count({i.first-1, i.second});
		if(c == 4)
			cnt++;
		if(c != 4 and c != 2){
			cout<<"no "<<i.first<<' '<<i.second<<' '<<c<<endl;
		}
		assert(c == 4 or c == 2);
	}
	print(in, cnt);
	assert(cnt == in);
	assert(ff);
}