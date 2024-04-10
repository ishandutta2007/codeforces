#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
const int N = 100005;
int f[4]={0};

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return (a*pw(a,b-1))%MOD;
	ll t = pw(a,b/2);
	return (t*t)%MOD;
}

int mp(char c) {
	if(c == 'A') return 0;
	if(c == 'C') return 1;
	if(c == 'T') return 2;
	return 3;
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	string s;
	cin >> s;

	for(int i = 0; i < s.size(); ++i)
		++f[mp(s[i])];

	int mx = max(max(f[0],f[1]),max(f[2],f[3]));
	int amt_max = 0;
	int char_max = 0;
	for(int i = 0; i < 4; ++i) {
		if(f[i] == mx) {
			++amt_max;
			char_max += f[i];
		}
	}
	cout << pw(amt_max, n) << "\n";
	return 0;
}