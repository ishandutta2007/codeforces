#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll a = 1234567;
const ll b = 123456;
const ll c = 1234;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;	cin >> n;
	for (ll aa = 0; aa * a <= n; aa++){
		ll rem = n - a * aa;
		for (ll bb = 0; bb * b <= rem; bb++){
			ll tr = rem - bb * b;
			if (tr % c == 0){
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}