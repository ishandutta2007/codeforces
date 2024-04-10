#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T s){std::cerr<<s<<std::endl;}
template<typename T, typename... Args> void pr(T s, Args... args){std::cerr<<s<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 2e5+5;

int tc, n, s[MM], t[MM];
vector<int> v[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>s[i];
			v[s[i]].emplace_back(i);
		}

		priority_queue<pair<int, int>> st;
		for(int i = 1; i <= n; i++){
			if(size(v[i])){
				st.push({size(v[i]), i});
			}
		}

		vector<int> ord;

		while(size(st) > 1){
			int i = st.top().second;
			st.pop();
			int j = st.top().second;
			st.pop();
			int a = v[i].back();
			v[i].pop_back();
			int b = v[j].back();
			v[j].pop_back();
			ord.emplace_back(a);
			ord.emplace_back(b);
			if(size(v[i]))
				st.push({size(v[i]), i});
			if(size(v[j]))
				st.push({size(v[j]), j});
		}
		while(size(st)){
			int i = st.top().second;
			st.pop();
			int a = v[i].back();
			v[i].pop_back();
			ord.emplace_back(a);
			if(size(v[i]))
				st.push({size(v[i]), i});
		}

		for(int i = 0; i < n; i++){
			int cur = ord[i], nx = ord[(i+1)%n];
			t[cur] = s[nx];
		}

		for(int i = 0; i < n; i++){
			cout<<t[i]<<' ';
		}
		cout<<'\n';

		for(int i = 1; i <= n; i++){
			v[i].clear();
		}
	}
}
/*
1
3
1 2 3

*/