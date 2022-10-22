#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 20;

ll n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	sort(vec, vec + n);
	ll ans = vec[n - 1] - vec[0];
	if (vec[0] == vec[n - 1]){
		cout << ans << " " << n * (n - 1)/ 2 << endl;
		return	0;	
	}
	ll a = 1;
	while (a < n && vec[a] == vec[0])	a++;
	ll b = n - 1;
	while (b && vec[b - 1] == vec[n - 1])	b--;
	b = n - b;
	cout << ans << " " << a * b << endl;
	return	0;
}