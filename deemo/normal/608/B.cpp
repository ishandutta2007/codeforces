#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;

string s, t;
int p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t >> s;
	for (int i = 0; i < s.size(); i++)
		p[i + 1] = p[i] + bool(s[i] == '1');

	ll ans = 0;
	for (int i = 0; i < t.size(); i++){
		int temp =  p[i + (int)s.size() - (int)t.size() + 1] - p[i];
		if (t[i] == '0')
			ans += temp;
		else
			ans += ((int)s.size() - (int)t.size() + 1) - temp;
	}
	cout << ans << endl;
	return 0;
}