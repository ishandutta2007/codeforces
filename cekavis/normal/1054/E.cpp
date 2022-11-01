#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 305, M = 100005;
int n, m, x;
deque<char> s[N][N];
vector<ll> ans[2];
inline void move(int a, int b, int c, int d){
	if(a==c && b==d) return;
	ans[x].push_back(((ll)a<<30)|(b<<20)|(c<<10)|d);
	s[c][d].push_front(s[a][b].back()), s[a][b].pop_back();
}
void solve(){
	for(int i=2; i<=m; ++i) while(!s[1][i].empty()) move(1, i, 1, 1);
	for(int i=2; i<=n; ++i) while(!s[i][1].empty()) move(i, 1, 1, 1);
	while(!s[1][1].empty())
		if(s[1][1].back()=='1') move(1, 1, 2, 1); else move(1, 1, 1, 2);
	for(int i=2; i<=n; ++i) for(int j=2; j<=m; ++j) while(!s[i][j].empty())
		if(s[i][j].back()=='1') move(i, j, i, 1), move(i, 1, 2, 1);
		else move(i, j, 1, j), move(1, j, 1, 2);
}
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		string S;
		cin>>S;
		for(auto c:S) s[i][j].push_back(c);
	}
	solve();
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
		string S;
		cin>>S, reverse(S.begin(), S.end());
		s[i][j].clear();
		for(auto c:S) s[i][j].push_back(c);
	}
	x=1, solve(), reverse(ans[1].begin(), ans[1].end());
	printf("%d\n", ans[0].size()+ans[1].size());
	for(ll i:ans[0]) printf("%lld %lld %lld %lld\n", i>>30, i>>20&1023, i>>10&1023, i&1023);
	for(ll i:ans[1]) printf("%lld %lld %lld %lld\n", i>>10&1023, i&1023, i>>30, i>>20&1023);
	return 0;
}