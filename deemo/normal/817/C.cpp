#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

ll d[20][200][2];

ll get(ll tr, ll sm){
	stringstream ss; ss << tr;
	string s; ss >> s;
	
	memset(d, 0, sizeof(d));
	d[0][0][1] = 1;
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j <= sm; j++){
			for (int w = 0; w < s[i]-'0'; w++)
				d[i+1][j+w][0] += d[i][j][1];
			d[i+1][j+(int)(s[i]-'0')][1] += d[i][j][1];
			for (int w = 0; w < 10; w++)
				d[i+1][j+w][0] += d[i][j][0];
		}
	return d[s.size()][sm][0] + d[s.size()][sm][1];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, s; cin >> n >> s;

	ll ans = 0;
	for (int i = 1; i <= 18*9; i++){
		ll tl = i+s;
		ll tr = n;
		if (tl <= tr)
			ans += get(tr, i) - get(tl-1, i);
	}
	cout << ans << endl;
	return 0;
}