#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2e5 + 10;

int n, m, T, vec[MAXN];
ld p[MAXN];
ld c;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> T >> c;
	for (int i = 0; i < n; i++)
		cin >> vec[i], p[i + 1] = p[i] + vec[i];

	int q, cur = 0;	cin >> q;
	ld apx = 0;
	while (q--){
		int t;	cin >> t;
		while (cur < t){
			apx = (apx + (ld)vec[cur]/ ld(T)) / c;
			cur++;
		}
		ll sm = p[t] - p[t - T];
		ld real = ld(sm)/ ld(T);
		cout << real << " " << apx << " " << abs((apx - real))/ real << "\n";
	}
	return	0;
}