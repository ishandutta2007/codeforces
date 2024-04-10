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

int t, n;
int a[MM], b[MM], cnt[MM];

bool run(){
	cin>>n;
	for(int i = 0; i <= n; i++){
		cnt[i] = 0;
	}
	for(int i = 0; i < n; i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}
	int sub = 0;
	a[n] = 1e9;
	b[n] = 1e9;
	multiset<int> st;
	for(int i = n-1; i >= 0; i--){
		top:;
		// pr(i, i-sub, ",", a[i], b[i-sub]);
		int c = b[i-sub];
		if(i-sub >= 0 and a[i] == b[i-sub]){

		}
		else if(i-sub >= 0 and b[i-sub] == b[i-sub+1] and cnt[c]){
			// take a c
			st.insert(c);
			cnt[c]--;
			// pr("ins", b[i-sub]);
			sub++;
			goto top;
		}
		else if(st.find(a[i]) != st.end()){
			st.erase(st.find(a[i]));
			sub--;
			continue;
		}
		else{
			return 0;
		}
		cnt[a[i]]--;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--) cout<<(run()?"YES":"NO")<<'\n';
}
/*
2
6
2 4 3 2 3 2
2 4 3 3 2 2
6
2 4 3 2 3 2
4 2 3 3 2 2
*/