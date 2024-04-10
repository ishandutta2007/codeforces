#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

#define pb(x) push_back(x)

const int max_n = 1e5 + 300;

int n, q;
vector<int>	a;
int mp[max_n];
int ans[max_n];

int main(){
	scanf("%d%d", &n, &q);
	a.resize(n);

	int cnt = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		mp[a[i]]++;
		if (mp[a[i]] == 1)	cnt++;
	}
	
	for (int i = 0; i < n; i++){
		ans[i] = cnt;
		if (mp[a[i]] == 1)	cnt--;
		mp[a[i]]--;
	}
	
	while (q--){
		int temp;	scanf("%d", &temp);
		temp--;
		printf("%d\n", ans[temp]);
	}

	return 0;
}