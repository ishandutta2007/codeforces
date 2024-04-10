#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
struct Event{int index; int value; int tm; int tp;};
vector<multiset<int> > t;
vector<int> if_zero;
bool cmp(Event &a, Event &b){
	return (a.tm < b.tm);
}
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, w;
	cin >> n >> w;
	vector<Event> ev;
	vector<int> sz;
	for (int i=0; i < n; i++){
		int k;
		cin >> k;
		sz.push_back(k);
		for (int j=0; j < k; j++){
			int x;
			cin >> x;
			int L = j;
			int R = j+(w-k);
			ev.push_back({i, x, L, 1});
			ev.push_back({i, x, R+1, 0});
		}
		if (k != w){
			ev.push_back({i, 0, 0, 1});
			ev.push_back({i, 0, w-k, 0});
			ev.push_back({i, 0, k, 1});
			ev.push_back({i, 0, w, 0});
		}
	}
	sort(ev.begin(), ev.end(), cmp);
	t.assign(n, {});
	if_zero.assign(n, 0);
	ll ans = 0;
	int u = 0;
	for (int i=0; i < w; i++){
		while (u < ev.size() && ev[u].tm == i){
			int arr = ev[u].index;
			if (t[arr].size()){
				int M = -(*t[arr].begin());
				if (if_zero[arr]) M = max(M, 0);
				ans -= M;
			}
			if (ev[u].tp == 1){
				if (ev[u].value == 0) if_zero[arr]++;
				else t[arr].insert(-ev[u].value);
			}
			else {
				if (ev[u].value == 0) if_zero[arr]--;
				else t[arr].erase(t[arr].find(-ev[u].value));
			}
			if (t[arr].size()){
				int M = -(*t[arr].begin());
				if (if_zero[arr]) M = max(M, 0);
				ans += M;
			}
			u++;
		}
		cout << ans << " ";
	}
}