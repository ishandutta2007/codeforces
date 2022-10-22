#include<cstdio>
#include<vector>

using namespace std;

int main(){
	int ans = 0, t = 0, n;
	scanf("%d", &n);
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	for (int i = 1; i < n - 1; i++)
		if (vec[i - 1] == vec[i + 1] && vec[i - 1] == 1)	vec[i] = 1;
	for (int i = 0; i < n; i++)
		if (vec[i])	ans++;
	printf("%d\n", ans);
	return 0;
}