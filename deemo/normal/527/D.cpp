#include<cstdio>
#include<algorithm>
#include<utility>

using namespace std;

typedef long long ll;

const int max_n = 2e5 + 100;

int n;
pair<int, int>	a[max_n];

bool cmp(pair<int, int>	a, pair<int, int>	b){return	a.second < b.second;}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d", &a[i].first, &a[i].second);
		a[i].first -= a[i].second;
		a[i].second = a[i].first + a[i].second * 2;
	}
	sort(a, a + n, cmp);
	int ans = 0;
	pair<int, int>	temp;
	for (int i = 0; i < n; i++){
		if (ans == 0){
			temp = a[i];
			ans++;
			continue;
		}
		if (a[i].first < temp.second)	continue;
		temp = a[i];
		ans++;
	}		
	printf("%d\n", ans);
	return 0;
}