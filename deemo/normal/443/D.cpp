#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 100 + 5;

int n;
ld vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> vec[i];
	sort(vec, vec + n);
	ld ans = vec[n - 1];

	for (int l = 0; l < n; l++)
		for (int r = l + 1; r <= n; r++){
			ld ret = 0, sum = 1;
			for (int k = l; k < r; k++)
				sum = sum * (1.0 - vec[k]);
			for (int k = l; k < r; k++)
				ret += vec[k] * (sum/ (1.0 - vec[k]));
			ans = max(ans, ret);
		}
	cout << ans << endl;
	return	0;
}