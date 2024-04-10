#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 200005;
int n;
int s[maxn], r[maxn];
int sta[maxn], top;
vector<int> w;

ll cross(int i, int j, int k){
	return (ll)(s[i] - s[j]) * (r[i] - r[k]) * r[j] * s[k] - (ll)(r[i] - r[j]) * (s[i] - s[k]) * s[j] * r[k];
}

int main(){
	scanf("%d", &n);
	map<pair<int, int>, vector<int> > mp;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", s + i, r + i);
		if(!mp.count(mkp(s[i], r[i]))) w.pb(i), mp[mkp(s[i], r[i])].pb(i);
		else mp[mkp(s[i], r[i])].pb(i);
	}
	sort(all(w), [](int i, int j){
			return s[j] < s[i] || (s[j] == s[i] && r[i] < r[j]);
		});
	for(int x : w){
		while(top > 1 && cross(sta[top - 1], sta[top], x) < 0) --top;
		if(s[x] > s[sta[top]] || r[x] > r[sta[top]])
			sta[++top] = x;
	}
	int lt = 1, rt = top;
	while(lt < rt && s[sta[lt]] == s[sta[lt + 1]] && r[sta[lt]] <= r[sta[lt + 1]]) ++lt;
	while(lt < rt && r[sta[rt]] == r[sta[rt - 1]] && s[sta[rt]] <= s[sta[rt - 1]]) --rt;

	vector<int> ans;
	for(int i = lt; i <= rt; ++i)
		for(int v : mp[mkp(s[sta[i]], r[sta[i]])])
			ans.pb(v);

	sort(all(ans));
	for(int v : ans) printf("%d ", v);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}