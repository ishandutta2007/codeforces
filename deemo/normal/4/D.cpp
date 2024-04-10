#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

const int max_n = 6e3;

int n, a, b;
vector<pair<int, int>>	vec;
vector<pair<pair<int, int>, int>>	sec;
int d[max_n], par[max_n];

bool cmp(pair<pair<int, int>, int>	a, pair<pair<int, int>, int>	b){
	return	a.first < b.first;
}

void show(int ind){
	if (par[ind] != 0)	show(par[ind] - 1);
	printf("%d ", sec[ind].second);
}

int main(){
	scanf("%d%d%d", &n, &a, &b);
	vec.resize(n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &vec[i].first, &vec[i].second);
		if (vec[i].first <= a || vec[i].second <= b)	vec[i].first = -1;
		if (vec[i].first != -1)
			sec.push_back({vec[i], i + 1});
	}
	sort(sec.begin(), sec.end(), cmp);	

	int ans = 0, g = -1;
	for (int i = 0; i < sec.size(); i++){
		int j = i;
		while (j >= 0 && sec[j].first.first == sec[i].first.first)	j--;
		
		int maxi = 1, ind = -1;
		for (;j >= 0; j--)
			if (sec[j].first.second < sec[i].first.second)
				if (maxi < d[j] + 1){
					maxi = d[j] + 1;
					ind = j;
				}		
		par[i] = ind + 1;
		d[i] = maxi;

		if (ans < maxi)	ans = maxi, g = i + 1;
	}
	printf("%d\n", ans);
	if (ans == 0)	return	0;
	show(g - 1);
	printf("\n");
	return 0;
}