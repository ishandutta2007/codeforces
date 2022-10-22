#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	int n;	cin >> n;
	vector<ll>	vec(n), sec(n);
	ll k = 1;
	for (int i = 0; i < n; i++)	cin >> vec[i], k = k/__gcd(k, vec[i]) * vec[i];
	for (int i = 0; i < n; i++)	cin >> sec[i];
	int cnt = 0;
	for (int i = 0; i < k; i++){
		bool fl = 0;
		for (int j = 0; j < n; j++)
			if (i % vec[j] == sec[j])	fl = 1;
		if (fl)
			cnt++;
	}
	cout << fixed << setprecision(12);
	cout << ld(cnt)/ ld(k) << "\n";
	return	0;
}