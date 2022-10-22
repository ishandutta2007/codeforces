#include<cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;
#define left first
#define right second

const int MOD = 1e9 + 7;
const int max_n = 1e5 + 100;

int n, m;
pair<int, int>	vec[max_n];
ll d[max_n], p[max_n];

bool cmp(pair<int, int>	a, pair<int, int> b){
	if (a.right != b.right)
		return	a.right < b.right;
	return	a.left < b.left;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &vec[i].left, &vec[i].right);

	sort(vec, vec + m, cmp);
	int ind = -1;
	for (int i = 0; i < m; i++){
		if (vec[i].left == 0)	d[i] = 1;
		if (i != 0 && vec[i].right != vec[i - 1].right)	ind = i - 1;

		int b = 0, e = i - 1, ret = -1, mid;
		while (b <= e){
			mid = (b + e)/ 2;
			if (vec[mid].right < vec[i].left){
				ret = mid;
				b = mid + 1;
			}
			else	e = mid - 1;
		}		
		if (ret != -1)	d[i] = (d[i] + (p[ind] + MOD - p[ret])) % MOD;
		else	d[i] = (d[i] + p[ind]) % MOD; 
		
		if (i != 0)	p[i] = p[i - 1] + d[i];
		else	p[i] = d[i];
		p[i] %= MOD;
	}
	
	ll ans = 0;
	for (int i = 0; i < m; i++)
		if (vec[i].right == n)	ans = (ans + d[i]) % MOD;
	printf("%d\n", (int)ans);
	return 0;
}