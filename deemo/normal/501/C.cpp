#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

int n;
vector<int>	d, s, vec;
vector<pair<int, int>>	ans;

int main(){
	scanf("%d", &n);
	d.resize(n);
	s.resize(n);

	for (int i = 0; i < n; i++){
		scanf("%d%d", &d[i], &s[i]);
		if (d[i] == 1)
			vec.push_back(i);
	}	

	while (!vec.empty()){
		int t = vec.back();
		vec.pop_back();
		if (d[t] == 0)	continue;
		
		ans.push_back({t, s[t]});
		d[t]--;
		d[s[t]]--;
		s[s[t]] ^= t;
		if (d[s[t]] == 1)	vec.push_back(s[t]);
	}

	printf("%d\n", (int)ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}