#include <bits/stdc++.h>
	  
using namespace std;
	  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

ll n, a, b, k, f;
map<pair<string, string>, ll> was;

int main() { 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen("cpr.in", "r", stdin);
	//freopen("cpr.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> a >> b >> k >> f;
	string last;
	for (int i = 0; i < n; i++){
		string s1, s2;
		cin >> s1 >> s2;
		ll cc = a;
		if (i != 0 && s1 == last) cc = b; 
		last = s2;
		if (s1 > s2) swap(s1, s2);
		was[mp(s1, s2)] += cc;
	}
	vector<ll> tt;
	for (auto c : was) tt.pub(c.y);
	sort(all(tt));
	reverse(all(tt));
	ll ans = 0;

	for (int i = 0; i < tt.size(); i++){
		if (k > 0 && tt[i] > f){
			k--;
			ans += f;
		} else ans += tt[i];
	}

	cout << ans;
}