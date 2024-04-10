#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const ll MAXN = 1e5 + 100;

ll n;
pair<ll, ll>	vec[MAXN], sec[MAXN];

bool bad(pair<ll, ll>	a, pair<ll, ll>	b, pair<ll, ll>	c){
	return	(b.F - a.F) * (c.S - a.S) - (b.S - a.S) * (c.F - a.F) == 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)	cin >> vec[i].F >> vec[i].S;
	copy(vec, vec + n, sec);
	sort(vec, vec + n);
	auto a = vec[0], b = vec[1], c = vec[2];
	ll i = 3;
	while (bad(a, b, c))
		c = vec[i++];
	for (ll i = 0; i < n; i++)
		if (sec[i].F == a.first && sec[i].S == a.second)	cout << i + 1 << " ";
	for (ll i = 0; i < n; i++)
		if (sec[i].F == b.first && sec[i].S == b.second)	cout << i + 1 << " ";
	for (ll i = 0; i < n; i++)
		if (sec[i].F == c.first && sec[i].S == c.second)	cout << i + 1 << " ";
	cout << "\n";
	return	0;
}