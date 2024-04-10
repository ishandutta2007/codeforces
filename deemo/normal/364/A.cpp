#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

const ll MAXN = 4e3 + 20;

ll a, n;
string s;
map<ll, ll>	cn;

int main(){
	cin >> a >> s;
	n = s.size();
	for (ll i = 0; i < n; i++){
		ll sum = 0;
		for (ll j = i; j < n; j++){
			sum += s[j] - '0';
			cn[sum]++;
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++){
		ll sum = 0;
		for (ll j = i; j < n; j++){
			sum += s[j] - '0';
			if (sum == 0){
				if (a == 0)
					ans += n * (n - 1)/2 + n;
			}
			else if (a % sum == 0)
				ans += cn[a/sum];
		}
	}
	cout << ans << endl;
	return 0;	
}