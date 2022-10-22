#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
ll ans;

int main(){
	scanf("%d", &n);
	vector<int>	vec(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());
	for (int i = n; i; i /= 4)
		for (int j = n - 1; j > n - 1 - i; j--)
			ans += vec[j];
	printf("%I64d\n", ans);
	return 0;
}