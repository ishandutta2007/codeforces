#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 20;

ll n, vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	
	ll ans = 0;
	for (ll i = 0; i < n;){
		ans++;
		ll j = i, ta = 0, tb = 0;
		vector<ll>	sec;
		while (j < n && vec[j] == -1)	j++, ta++;
		
		while (j < n && sec.size() < 2){
			if (vec[j] > -1)
				sec.push_back(vec[j]);
			j++, tb++;
		}
		tb--;
		if (sec.size() < 2)	break;
		
		ll a = sec[0], b = sec[1];
		if (a == b){
			ll d = 0;
			while (j < n && (vec[j] == -1 || vec[j] == a))	j++;
		}
		else if (a < b){
			ll dif = (b - a);
			if (dif % tb || a - ta * (dif/tb) <= 0)	j--;
			else{
				ll d = dif / tb;
				b += d;
				while (b > 0 && j < n && (vec[j] == b || vec[j] == -1))	j++, b += d;
			}
		}
		else{
			ll dif = a - b;
			if (dif % tb)	j--;
			else{
				ll d = dif/tb;
				b -= d;
				while (b > 0 && j < n && (vec[j] == b || vec[j] == -1))	j++, b -= d;
			}
		}
		i = j;
	}
	cout << ans << endl;
	return 0;
}