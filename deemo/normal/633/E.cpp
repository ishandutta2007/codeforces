#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<numeric>
#include<iomanip>
#include<functional>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1e6 + 10;
const int LOG = 20 + 2;

int n, k;
int v[MAXN], c[MAXN], save[MAXN];
int ss[LOG][MAXN], tt[LOG][MAXN];
ld sp[MAXN], ans[MAXN];

void init(){
	for (int i = 1; i < LOG; i++)
		for (int j = 0; j < n; j++)
			if (j + (1<< (i - 1)) >= n)
				ss[i][j] = ss[i - 1][j], tt[i][j] = tt[i - 1][j];
			else{
				ss[i][j] = max(ss[i - 1][j], ss[i - 1][j + (1 << (i - 1))]);
				tt[i][j] = min(tt[i - 1][j], tt[i - 1][j + (1 << (i - 1))]);
			}

	for (int i = 1, j = 0; i < MAXN; i += (1<<j), j++)
		for (int w = i; w < (i + (1<<j)) && w < MAXN; w++)
			save[w] = j;
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)	scanf("%d", &v[i]), ss[0][i] = v[i];
	for (int i = 0; i < n; i++)	scanf("%d", &c[i]), tt[0][i] = c[i];
	init();

	for (int i = 0; i < n; i++){
		int j = i;
		for (int w = LOG - 1; w >= 0; w--)
			if (j + (1<<w) <= n){
				int sz = (j + (1<<w)) - i;
				if (100 * max(ss[save[sz]][i], ss[save[sz]][j + (1<<w) - (1<<save[sz])]) <= min(tt[save[sz]][i], tt[save[sz]][j + (1<<w) - (1 << save[sz])]))
					j += (1<<w);
			}
	
		if (i != j)
			ans[i] = min(min(tt[save[j - i]][i], tt[save[j - i]][j - (1<< save[j - i])]), 100 * max(ss[save[j-i]][i], ss[save[j - i]][j - (1<<save[j - i])]));
		if (j != n){
			j++;
			ans[i] = max(ans[i], (ld)min(min(tt[save[j - i]][i], tt[save[j - i]][j - (1<< save[j - i])]), 100 * max(ss[save[j-i]][i], ss[save[j - i]][j - (1<<save[j - i])])));
		}
	}
	sort(ans, ans + n, greater<ld>());

	cout << fixed << setprecision(14);
	ld p = 1.0, ret = 0;
	for (int i = n - 1; i >= k - 1; i--){
		sp[i] = p;
		p *= ld(i + 1 - k)/ ld(i + 1);
	}
	for (int i = n - 1; i >= k - 1; i--){
		if (i == 0)
			ret += sp[i] * ans[i];
		else
			ret += (sp[i] - sp[i - 1]) * ans[i];
	}
	cout << ret << "\n";
	return	0;
}