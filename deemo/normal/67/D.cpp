#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e6 + 20;

int n;
int vec[MAXN], pos[MAXN];
vector<int>	ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i]);	vec[i]--;
		pos[vec[i]] = i;
	}
	for (int i = 0; i < n; i++){
		int temp;	scanf("%d", &temp);	temp--;
		vec[pos[temp]] = i;
	}
	reverse(vec, vec + n);

	for (int i = 0; i < n; i++){
		int pos = lower_bound(ans.begin(), ans.end(), vec[i]) - ans.begin();
		if (pos == ans.size())
			ans.push_back(vec[i]);
		else
			ans[pos] = vec[i];
	}
	printf("%d\n", (int)ans.size());
	return 0;	
}