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
	if (vec.size() == 1){
		printf("%d\n", vec[0]);
		return 0;
	}
	long long sum = 0;
	for (int i = 0; i < vec.size() - 1; i++)
		sum += (long long)(i + 2) * vec[i];
	sum += (long long)n * vec.back();
	printf("%I64d\n", sum);
	return 0;
}