#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int n, s;
vector<pair<int , int>>	vec;

int main(){
	scanf("%d%d", &s, &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &vec[i].first, &vec[i].second);
	sort(vec.begin(), vec.end());
	
	for (int i = 0; i < n; i++){
		if (s <= vec[i].first){
			printf("NO\n");
			return 0;
		}
		s += vec[i].second;
	}

	printf("YES\n");
	return 0;
}