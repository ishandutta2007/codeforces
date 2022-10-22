//Strange things did happen here No stranger would it be
//If we met at midnight In the hanging tree.
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const int MAX_VAL = 5e5;
const int MAX_N = 2e5;

int n, q, cnt;
ll ans;
int a[MAX_N], save[MAX_VAL + 100];
vector<int>	fac[MAX_VAL + 100];
bool npr[MAX_VAL + 100];
bool mark[MAX_N];

void init(){
	npr[1] = 1;
	for (int i = 2; i <= MAX_VAL; i++){
		if (npr[i])	continue;
		for (int j = i; j <= MAX_VAL; j += i){
			fac[j].push_back(i);
			npr[j] = 1;
		}
	}
}

int get(int x){
	int z = 1 << (fac[x].size());
	int sum = 0;
	for (int i = 1; i < z; i++){
		int t = i, c = 1;
		for (int j = 0; t; j++, t >>= 1)
			if (t & 1)	c *= fac[x][j];
		int g = __builtin_popcount(i);
		if (g % 2 == 1)	sum += save[c];
		else	sum -= save[c];	
	}
	return	cnt - sum;
}

void add(int x, int val){
	int z = 1 << (fac[x].size());
	for (int i = 1; i < z; i++){
		int t = i, c = 1;
		for (int j = 0; t; j++, t >>= 1)
			if (t & 1)	c *= fac[x][j];
		save[c] += val;
	}
}

int main(){
	init();
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	while (q--){
		int ind;	scanf("%d", &ind);	ind--;
		if (a[ind] == 1){
			if (mark[ind])	cnt--, ans -= cnt;
			else	ans += cnt, cnt++;
			printf("%I64d\n", ans);
			mark[ind] = !mark[ind];
			continue;
		}

		int t = get(a[ind]);
		if (mark[ind]){
			ans -= t, cnt--;
			add(a[ind], -1);
		}
		else{
			ans += t, cnt++;
			add(a[ind], 1);
		}
		printf("%I64d\n", ans);
		mark[ind] = !mark[ind];
	}
	return 0;
}