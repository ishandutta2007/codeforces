#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int>	vec;

int main(){
	scanf("%d", &n);
	vec.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());
	for (auto i:vec)
		printf("%d ", i);
	printf("\n");
	return 0;
}