#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<pair<int, int> > ans;

string t;

void add(string &s, int l, int r){
	t = "";
	for (int j=r; j >= l; j--) t += s[j];
	for (int j=l; j <= r; ++j) s[j] = t[j-l];
	ans.push_back({l, r});
}

void solve(){
	ans.clear();

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int cur = 0;
	for (int i=0; i < k-1; ++i){
		for (int j=cur; j < n; ++j){
			if (s[j] == '('){
				add(s, cur, j);
				break;
			}
		}
		cur++;
		for (int j=cur; j < n; ++j){
			if (s[j] == ')'){
				add(s, cur, j);
				break;
			}
		}
		cur++;
	}

	for (int i=0; i < n/2-(k-1); ++i){
		for (int j=cur; j < n; ++j){
			if (s[j] == '('){
				add(s, cur, j);
				break;
			}
		}
		cur++;
	}

	for (int i=0; i < n/2-(k-1); ++i){
		for (int j=cur; j < n; ++j){
			if (s[j] == ')'){
				add(s, cur, j);
				break;
			}
		}
		cur++;
	}

	cout << ans.size() << "\n";
	for (int i=0;i<ans.size();++i){
		cout << ans[i].first+1 << " " << ans[i].second + 1 << "\n";
	}

}

int main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}