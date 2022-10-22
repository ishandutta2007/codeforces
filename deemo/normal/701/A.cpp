#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;

int n, a[MAXN], sm;
vector<int>	vec[200];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), sm += a[i];
	sm /= n/2;
	for (int i = 0; i < n; i++)
		vec[a[i]].push_back(i + 1);
	for (int i = 0; i < MAXN; i++)
		while (vec[i].size()){
			int a = vec[i].back();
			vec[i].pop_back();
			int b = vec[sm - i].back();
			vec[sm - i].pop_back();
			printf("%d %d\n", a, b);
		}
	return 0;
}