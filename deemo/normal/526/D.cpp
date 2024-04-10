#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

typedef long long ll;

const ll max_n = 1e6 + 100;

ll n, k;
string s;
ll z[max_n], mark[max_n];

void init(){
	ll L = 0, R = 0;
	for (ll i = 1; i < s.size(); i++){
		if (R <= i){
			L = R = i;
			while (R < s.size() && s[R] == s[R - L])	R++;
			z[i] = R - L;
		}	
		else{
			ll k = i - L;
			if (z[k] < R - i)
				z[i] = z[k];
			else{
				L = i;
				while (R < s.size() && s[R] == s[R - L])	R++;
				z[i] = R - L;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	cin >> s;
	init();

	for (ll i = 1; i <= s.size(); i++){
		ll j = k * i;
		if (z[i] < j - i)	continue;
		if (j > s.size())	continue;

		ll t = min(z[j], i);
		mark[j - 1] += 1;
		mark[j + t] -= 1;
	}	

	long long cnt = 0;
	for (ll i = 0; i < s.size(); i++){
		cnt += mark[i];
		if (cnt)	
			cout << "1";
		else
			cout << "0";
	}
	cout << "\n";
	return 0;
}