#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 2e5+5;

int tt, n;
string s;

bool check(string t){
	int cnt = 0;
	for(auto c: t){
		if(c == '(')
			cnt++;
		else
			cnt--;
		if(cnt < 0)
			return 0;
	}
	return 1;
}

int sum(string t){
	int cnt = 0;
	for(auto c: t){
		if(c == '(')
			cnt++;
		else if(c == ')')
			cnt--;
	}
	return cnt;
}

bool run(){
	cin>>s;
	n = size(s);
	if(n%2) return 0;
	deque<int> v;
	for(int i = 0; i < n; i++){
		if(s[i] == '?')
			v.push_back(i);
	}
	int dif = sum(s);
	while(dif > 0){
		if(!size(v)) return 0;
		int i = v.back(); v.pop_back();
		s[i] = ')';
		dif--;
	}
	while(dif < 0){
		if(!size(v)) return 0;
		int i = v.front(); v.pop_front();
		s[i] = '(';
		dif++;
	}
	int m = size(v);
	assert(m%2 == 0);
	for(int i = 0; i < m; i++){
		if(i < m/2)
			s[v[i]] = '(';
		else
			s[v[i]] = ')';
	}
	int ok = check(s);
	if(m){
		int k = m/2;
		swap(s[v[k]], s[v[k-1]]);
		ok &= !check(s);
	}
	return ok;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>tt;
	while(tt--){
		cout<<(run()?"YES\n":"NO\n");
	}	
}