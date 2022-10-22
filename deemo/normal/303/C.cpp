#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAX = 1e6 + 200;
const int max_n = 5e3 + 20;

int n, k;
int a[max_n];
vector<pair<int, int>>	cnt[MAX];
int fg[MAX];
int mark[MAX], g;
int gg[MAX];
pair<int, int>	vec[200];

bool ok(int ans){
	int t = 0;
	for (int i = ans; i < MAX; i += ans){
		if (fg[i] > k * (k + 1)/ 2)	return	false;
		for (int j = 0; j < cnt[i].size(); j++){
			vec[t++] = cnt[i][j];
			if (t > k * (k + 1)/ 2)	return	false;
		}
	}

	g++;
	int c = 0;
	for (int i = 0; i < t; i++){
		int x = vec[i].first, y = vec[i].second;
		if (mark[x] != g && gg[a[x] % ans]++)	c++;
		mark[x] = g;
		if (mark[y] != g && gg[a[y] % ans]++)	c++;
		mark[y] = g;
		if (c > k)	break;
	}

	for (int i = 0; i < t; i++){
		pair<int, int>	temp = vec[i];
		gg[a[temp.first] % ans] = gg[a[temp.second] % ans] = 0;
	}
	return	c <= k;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			int x = a[j] - a[i];
			fg[x]++;
		}

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			int x = a[j] - a[i];
			if (fg[x] <= k * (k + 1)/2)
				cnt[x].push_back({i, j});
		}

	for (int i = 1; i < MAX; i++)
		if (ok(i)){
			printf("%d\n", i);
			return 0;
		}
	return 0;
}