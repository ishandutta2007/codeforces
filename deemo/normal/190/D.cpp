#include<cstdio>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 4e5 + 10;

long long ans = 0;
int n, k, a[MAXN];
map<int, int>	mp;

int main(){
	scanf("%d %d", &n, &k);
	int l = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		bool fl = 0;
		mp[a[i]]++;
		if (mp[a[i]] == k)	fl = 1;
		while (fl){
			ans += n - i;
			mp[a[l]]--;
			if (mp[a[l]] == k - 1)	fl = 0;
			l++;
		}
	}
	printf("%I64d\n", ans);
	return	0;
}