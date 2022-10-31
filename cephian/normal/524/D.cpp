#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int convert(string t) {
	int h = 10*(t[0]-'0') + t[1]-'0';
	int m = 10*(t[3]-'0') + t[4]-'0';
	int s = 10*(t[6]-'0') + t[7]-'0';
	return s + 60*m + 60*60*h;
}

const int N = 20005;
int times[N],n,m,t;

multiset<int> expire;
int users = 0, active = 0;
int ans[N],ex[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> t;
	bool achieved = 0;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		times[i] = convert(s);
	}
	bool rm = false;
	for(int i = 0; i < n; ++i) {
		while(expire.size() && *expire.begin() <= times[i]) {
			expire.erase(expire.find(*expire.begin()));
			--active;
		}
		if(active < m) {
			++active;
			ans[i] = ++users;
		} else {
			ans[i] = users;
			expire.erase(expire.find(ex[users]));
		}
		expire.insert(ex[users] = times[i] + t);
		rm |= active == m;
	}
	if(!rm) {
		cout << "No solution\n";
		return 0;
	}
	cout << users << "\n";
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << "\n";
	}
}