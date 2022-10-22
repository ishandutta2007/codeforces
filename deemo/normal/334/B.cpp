#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int, int>>	vec(8);
vector<int>	x, y;

int main(){
	for (int i = 0; i < 8; i++){
		scanf("%d%d", &vec[i].first, &vec[i].second);
		x.push_back(vec[i].first);
		y.push_back(vec[i].second);
	}	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	y.resize(unique(y.begin(), y.end()) - y.begin());
	if (x.size() != 3 || y.size() != 3){
		printf("ugly\n");
		return 0;
	}


	int cnt = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			if (i == j && i == 1)	continue;
			for (int k = 0; k < vec.size(); k++)
				if (vec[k].first == x[i] && vec[k].second == y[j]){
					cnt++;
					break;
				}
		}

	if (cnt != 8){
		printf("ugly\n");
		return 0;
	}
	printf("respectable\n");
	return 0;
}