#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

const int MAX = 3e5;
const int MAXN = 500 + 30;

int n, m;
int c[MAXN][MAXN];
bool p[MAX + 20];
set<int>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 2; i < MAX; i++){
		if (!p[i])	st.insert(i);
		for (int j = 2 * i; j < MAX; j += i)
			p[j] = 1;
	}

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int temp;	cin >> temp;
			c[i][j] = *st.lower_bound(temp) - temp;
		}

	ll ans = 1e18;
	for (int i = 0; i < n; i++){
		ll sum = 0;
		for (int j = 0; j < m; j++)
			sum += c[i][j];
		ans = min(ans, sum);
	}

	for (int j = 0; j < m; j++){
		ll sum = 0;
		for (int i = 0; i < n; i++)
			sum += c[i][j];
		ans = min(ans, sum);
	}
	cout << ans << endl;
	return 0;
}