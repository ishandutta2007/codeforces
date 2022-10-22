#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100 + 5;
const int MAGIC = 5e5 + 10;

int n;
ld d[MAXN], p[MAXN];

int main(){
	cout << fixed << setprecision(10);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i] /= 100., d[i] = p[i];
	
	ld ans = 1;
	for (int i = 0; i < n; i++)	ans *= d[i];
	ld lst = ans;
	ans *= n;

	for (int i = n + 1; i < MAGIC; i++){
		pair<ld, int>	mn(MAGIC, MAGIC);
		for (int j = 0; j < n; j++)
			mn = min(mn, {d[j]/ (1. - (1. - d[j]) * (1. - p[j])), j});

		int v = mn.second;
		d[v] = 1. - (1. - d[v]) * (1. - p[v]);

		ld temp = 1;
		for (int j = 0; j < n; j++)
			temp *= d[j];
		ans += (temp - lst) * i;
		lst = temp;
	}
	cout << ans << endl;
	return 0;
}