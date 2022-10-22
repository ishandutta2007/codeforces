#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n, k;
vector<int>	vec;

int main(){
	scanf("%d%d", &n, &k);
	vec.resize(2 * n);
	for (int i = 0; i < n; i++)
		vec[2 * i] = 2 * i + 1, vec[2 * i + 1] = 2 * i + 2;
	for (int i = 0; i < k; i++)
		swap(vec[2 * i], vec[2 * i + 1]);
	for (int i = 0; i < vec.size(); i++)
		printf("%d ", vec[i]);
	printf("\n");
	return 0;
}