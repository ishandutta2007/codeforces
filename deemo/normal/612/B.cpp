#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

int n;
int p[MAXN], f[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int cur;
	for (int i = 0; i < n; i++){
		cin >> p[i];
		p[i]--;
		if (p[i] == 0)	cur = i;
		f[p[i]] = i;
	}

	ll ans = 0;
	for (int i = 1; i < n; i++){
		int z = f[i];
		ans += abs(z - cur);
		cur = z;
	}
	cout << ans << endl;
	return 0;	
}