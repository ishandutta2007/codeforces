#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

int n, m, k, s, aa, bb, f[MAXN], g[MAXN];
pair<int, int>	vec[MAXN], sec[MAXN];
int ind = -1, mini = 1e6 + 40;
int mf[MAXN], mg[MAXN];
ll pa[MAXN], pb[MAXN];

void check(int a, int b){
	ll s1 = pa[a], s2 = pb[b];
	assert(a >= 0 && b >= 0);

	int beg = 1, e = min(n, mini), ret = mini + 1;
	while (beg <= e){
		int mid = (beg + e)/ 2;
		if ((ll)mf[mid] * s1 + (ll)mg[mid] * s2 <= s){
			ret = mid;
			e = mid - 1;
		}	
		else	beg = mid + 1;
	}
	if (ret < mini){
		mini = ret;
		ind = a;
	}
}

int main(){
	scanf("%d %d %d %d", &n, &m, &k, &s);
	mg[0] = mf[0] = 1e6 + 40;
	for (int i = 0; i < n; i++)	scanf("%d", &f[i]), mf[i + 1] = min(mf[i], f[i]);
	for (int i = 0; i < n; i++)	scanf("%d", &g[i]), mg[i + 1] = min(mg[i], g[i]);

	for (int i = 0; i < m; i++){
		int type;	scanf("%d", &type);
		if (type == 1)
			scanf("%d", &vec[aa].first), vec[aa++].second = i;
		else
			scanf("%d", &sec[bb].first), sec[bb++].second = i;
	}
	sort(vec, vec + aa);
	sort(sec, sec + bb);
	for (int i = 0; i < aa; i++)
		pa[i + 1] = pa[i] + vec[i].first;
	for (int i = 0; i < bb; i++)
		pb[i + 1] = pb[i] + sec[i].first;
	
	for (int i = 0; i <= aa && i <= k; i++)
		if (i + bb >= k)	check(i, k - i);
	
	if (ind == -1){
		printf("-1\n");
		return	0;
	}
	printf("%d\n", mini);
	int mina = 1e6 + 40, i1 = -1, minb = 1e6 + 40, i2 = -1;
	for (int i = 0; i < mini; i++){
		if (mina > f[i]){
			mina = f[i];
			i1 = i + 1;
		}	
		if (minb > g[i]){
			minb = g[i];
			i2 = i + 1;
		}
	}		
	for (int i = 0; i < ind; i++)
		printf("%d %d\n", vec[i].second + 1, i1);
	for (int i = 0; i < k - ind; i++)
		printf("%d %d\n", sec[i].second + 1, i2);
	return	0;
}