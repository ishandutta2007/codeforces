#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<utility>

using namespace std;

const int INF = 1e9;

int n;
vector<pair<int, int>>	vec;
vector<int>	sec;
map<int, int>	fr, bc;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &vec[i].first, &vec[i].second);
		fr[vec[i].first]++;
		if (vec[i].first != vec[i].second)	bc[vec[i].second]++;
		sec.push_back(vec[i].first);
		sec.push_back(vec[i].second);
	}	

	int ans = INF;
	for (int i = 0; i < sec.size(); i++){
		int t = sec[i];
		if ((fr[t] + bc[t]) * 2 < n)	continue;
		if (fr[t] * 2 >= n){
			ans = 0;
			break;
		}
		int temp = ceil(double(n)/2);
		temp -= fr[t];
		ans = min(ans, temp);
	}
	if (ans == INF)	ans = -1;
	printf("%d\n", ans);
	return 0;
}