#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

#define xx first.first
#define yy first.second

const int max_n = 1e5 + 40;

int n, p, k;
pair<pair<int, int>, int>	vec[max_n];
int mp[max_n];

bool cmp(pair<pair<int, int>, int>	a, pair<pair<int, int>, int>	b){
	if (a.yy != b.yy)
		return	a.yy > b.yy;
	if (a.xx != b.xx)
		return	a.xx > b.xx;
	return	a.second < b.second;
}

bool gcp(pair<pair<int, int>, int>	a, pair<pair<int, int>, int>	b){
	if (a.xx != b.xx)
		return	a.xx > b.xx;
	if (a.yy != b.yy)
		return	a.yy < b.yy;
	return	a.second < b.second;
}

int main(){
	scanf("%d%d%d", &n, &p, &k);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &vec[i].yy, &vec[i].xx);
		vec[i].second = i;
	}
	sort(vec, vec + n, gcp);
	for (int i = 0; i < n; i++)
		mp[vec[i].second] = i;
	sort(vec, vec + n - (p - k), cmp);
	int mini = 0;
	for (int i = 0; i < k; i++){
		printf("%d ", vec[i].second + 1);
		mini = max(mini, mp[vec[i].second]);
	}

	sort(vec, vec + n, gcp);
	for (int i = mini + 1; i < mini + 1 + (p - k); i++)
		printf("%d ", vec[i].second + 1);
	
	printf("\n");
	return 0;
}