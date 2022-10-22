#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 50 + 4;

int n, m;
ld w;
ld rem[MAXN];
vector<pair<ld, int>>	vec[MAXN];
vector<pair<ld, int>>	sec;

ld ab(ld x){
	if (x < 0)	return	-x;
	return	x;
}

int main(){
	cout << fixed << setprecision(13);
	cin >> n >> w >> m;
	ld sum = n * w;
	sum /= ld(m);
	for (int i = 0; i < n; i++)	sec.push_back({w, i});
	
	for (int i = 0; i < m; i++){
		rem[i] = sum;
		while (rem[i] > 1e-9){
			ld g = min(rem[i], sec.back().first);
			vec[i].push_back({g, sec.back().second});
			rem[i] -= g;
			if (ab(sec.back().first - w) > 1e-9 && ab(sec.back().first - g) > 1e-9){
				cout << "NO\n";
				return	0;
			}
			sec.back().first -= g;
			if (sec.back().first < 1e-9)	sec.pop_back();

		}
	}

	cout << "YES\n";
	for (int i = 0; i < m; i++){
		for (auto v:vec[i])
			cout << v.second + 1 << " " << v.first << " ";
		cout << "\n";
	}
	return	0;
}