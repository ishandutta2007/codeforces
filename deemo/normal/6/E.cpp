#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 50;
const int LOG = 20;

int n, k;
int vec[MAXN], ss[LOG][MAXN], tt[LOG][MAXN];
int save[MAXN];
vector<int>	ans;

void init(){
	for (int i = 0; i < n; i++)
		ss[0][i] = tt[0][i] = vec[i];
	for (int j = 1; j < LOG; j++)
		for (int i = 0; i < n; i++)
			if (i + (1 << (j - 1)) >= n)
				ss[j][i] = ss[j - 1][i], tt[j][i] = tt[j - 1][i];
			else{
				ss[j][i] = min(ss[j - 1][i], ss[j - 1][i + (1 << (j - 1))]);
				tt[j][i] = max(tt[j - 1][i], tt[j - 1][i + (1 << (j - 1))]);
			}

	save[2] = 0;
	for (int i = 3, j = 1; i < MAXN; i += (1 << j), j++)
		for (int w = i; w < MAXN && w < i + (1 << j); w++)
			save[w] = j;
}

bool ok(int x, bool t = 1){
	int sz = save[x];
	for (int i = 0; i <= n - x; i++)
		if (x == 1 || max(tt[sz][i], tt[sz][i + x - (1 << sz)]) - k <= min(ss[sz][i], ss[sz][i + x - (1 << sz)])){
			if (t)
				return	true;
			ans.push_back(i);
		}
	return	(int)ans.size();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	init();

	int b = 1, e = n, ret = 1;
	while (b <= e){
		int mid = (b + e)/ 2;
		if (ok(mid)){
			ret = mid;
			b = mid + 1;
		}		
		else	e = mid - 1;
	}
	ok(ret, 0);
	cout << ret << " " << ans.size() << "\n";
	for (int u:ans)
		cout << u + 1 << " " << u + ret << "\n";
	return 0;
}