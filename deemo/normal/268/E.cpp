#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int MAXN = 5e4 + 20;

int n;
pair<ll, ll>	vec[MAXN];
ld p[MAXN];

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.F * a.S * (100ll - b.S) > b.F * b.S * (100ll - a.S);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i].F >> vec[i].S;
	sort(vec, vec + n, cmp);

	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + (100. - vec[i].S)/100.;

	ld ans = 0;
	for (int i = 0; i < n; i++){
		ans += vec[i].F;
		ans += vec[i].S/100. * vec[i].F * (p[n] - p[i + 1]);
	}
	cout << ans << "\n";
	return 0;
}