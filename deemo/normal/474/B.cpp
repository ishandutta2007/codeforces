#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>

using namespace std;

const int max_n = 1e5 + 10;

int n, q;
vector<pair<int, int>>	sec;
vector<int>	vec;
int ans[max_n];

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	scanf("%d", &q);
	sec.resize(q);
	for (int i = 0; i < q; i++){
		scanf("%d", &sec[i].first);
		sec[i].second = i;
	}
	sort(sec.begin(), sec.end());
	
	int sum = 0, j = 0;
	for (int i = 0; i < n; i++){
		sum += vec[i];
		while (j < q && sec[j].first <= sum)
			ans[sec[j].second] = i + 1, j++;
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", ans[i]);
	return 0;
}