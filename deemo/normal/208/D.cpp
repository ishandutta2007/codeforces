#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

const ll MAXN = 50 + 5;

ll n, vec[MAXN], sec[MAXN], ans[MAXN];

int main(){
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	for (ll i = 0; i < 5; i++)	cin >> sec[i];

	ll sum = 0;
	for (ll i = 0; i < n; i++){
		sum += vec[i];
		for (ll j = 4; j >= 0; j--){
			ll z = sum / sec[j];
			ans[j] += z;
			sum -= z * sec[j];
		}
	}
	for (ll i = 0; i < 5; i++)
		cout << ans[i] << " ";
	cout << endl;
	cout << sum << endl;
	return 0;
}