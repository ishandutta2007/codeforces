#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int max_n = 1e5 + 20;

int n;
int a[max_n];
vector<int>	ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++){
		int pos = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
		if (pos == ans.size())
			ans.push_back(a[i]);
		else
			ans[pos] = a[i];
	}
	printf("%d\n", (int)ans.size());
	return 0;
}