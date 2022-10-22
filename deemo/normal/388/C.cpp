//What goes around, Comes around ;)

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 10;

ll n;
vector<ll>	vec[MAXN];
vector<ll>	sec[MAXN];
vector<ll>	gec;
ll c1, c2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll t;	cin >> t;	vec[i].resize(t);
		sec[i].resize(t + 1, 0);
		for (ll j = 0; j < t; j++){
			cin >> vec[i][j];
			sec[i][j + 1] = sec[i][j] + vec[i][j];
		}

		ll z = t/2 + bool(t % 2 == 1);
		c2 += sec[i][t] - sec[i][z];
		c1 += sec[i][t/2];
		if (t % 2)
			gec.push_back(vec[i][t/2]);
	}

	sort(gec.begin(), gec.end(), greater<ll>());
	for (ll i = 0; i < gec.size(); i++)
		if (i % 2 == 0)
			c1 += gec[i];
		else
			c2 += gec[i];
	cout << c1 << " " << c2 << endl;
	return 0;
}