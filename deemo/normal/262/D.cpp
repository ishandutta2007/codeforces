#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef double ld;

const int MAXN = 50 + 7;
const int MAX = MAXN * MAXN + 2;

int n, vec[MAXN];
ld d[MAXN][MAXN][MAX];
ld len, save[MAXN];
vector<int>	sec;

ld get(int x){
	if (n - 1 == 0)
		return	x <= len;
	d[0][0][0] = 1;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j <= n - 1; j++)
			for (int k = 0; k <= MAX; k++){
				d[i + 1][j][k] = d[i][j][k];
				if (j && sec[i] <= k)
					d[i + 1][j][k] += d[i][j - 1][k - sec[i]];
			}
	ld prob = 0;
	for (int j = 0; j <= n - 1; j++)
		for (int k = max(0, (int)len - x + 1); k <= MAX; k++)
			prob += d[n - 1][j][k] * save[j] * save[n - 1 - j];
	prob = save[n] - prob;
	return	prob/ save[n];
}

void init(){
	save[0] = 1;
	for (int i = 1; i < MAXN; i++)
		save[i] = (save[i - 1] * i);
}

int main(){
	cout << fixed << setprecision(12);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	cin >> len;
	init();

	ld ans = 0;
	for (int i = 0; i < n; i++){
		sec.assign(vec, vec + i);
		for (int j = i + 1; j < n; j++)
			sec.push_back(vec[j]);
		ans += get(vec[i]);
	}
	cout << ans << endl;	
	return 0;
}