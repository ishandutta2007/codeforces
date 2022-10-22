#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;

const int max_n = 2e5 + 40;

int n, k;
int a[max_n];
ll p[max_n], d[max_n], save[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		p[i + 1] = p[i] + a[i];
	}

	int f = 0, g = 0;
	ll maxi = d[k] = p[k];
	save[k] = 0;
	for (int i = k; i < n; i++){
		ll x = p[i + 1] - p[i + 1 - k];
		if (x + d[i + 1 - k] > maxi){
			f = save[i + 1 - k];
			g = i + 1 - k;
			maxi = x + d[i + 1 - k];
		}
		if (x <= d[i])
			save[i + 1] = save[i];
		else
			save[i + 1] = i + 1 - k;
		d[i + 1] = max(x, d[i]);
	}
	cout << f + 1 << " " << g + 1 << endl;
	return 0;
}