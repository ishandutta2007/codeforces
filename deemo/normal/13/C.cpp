//Sadra enghadr copy nakon codamo

#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 5e3 + 10;

ll n, vec[MAXN], sec[MAXN];
ll d[MAXN], c[MAXN];

bool cmp(ll u, ll v){return vec[u] < vec[v];}

int main(){
	cin >> n;	for (ll i = 0; i < n; i++)	cin >> vec[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			d[j] = abs(vec[i] - vec[sec[j]]);
			d[j] += c[j];
		}
		c[0] = d[0];
		for (ll j = 1; j < n; j++)
			c[j] = min(c[j - 1], d[j]);
	}

	cout << c[n - 1] << "\n";
	return	0;
}