#include <bits/stdc++.h>
#define future fdlkvfdlv
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


vector<pair<int, int> > trans;
vector<pair<int, int> > take;

int n;
int last_val;

int sum(int x) {
	if (x <= 0) return 0;
	return x*(x+1)/2;
}

int sum(int l, int r) {
	return sum(r) - sum(l-1);
}

bool possible(int x, int l, int r) {
	if (l > r) return false;
	if (sum(l, r) < x) return false;
	int a = 0, b = r-l+1;
	while (b - a > 1) {
		int c = (a+b)/2;
		if (sum(r-c+1, r) < x) a = c;
		else b = c;
	}

	if (sum(l, l+b-1) <= x) return true;
	return false;
}

vector<bool> restricted;
int future;

void recalc(vector<pair<int, int> > &non_zero, int l, int r, bool proh) {

	int a = non_zero[l].first;
	int b = non_zero[r].first;

	l = non_zero[l].second;
	r = non_zero[r].second;

	if (take.back().first > l) take.back().first = -1;
	if (take.back().second > l) take.back().second = -1;

	pair<int, int> res = make_pair(-1, -1);
	pair<int, int> tres = make_pair(-1, -1);

	for (int was = 0; was < 2; ++was) {
		if (was == 1 && a != b) continue;
		if (was == 0 && l != r && a == b) continue;
		if (was == 0 && proh) continue;

		if (was == 1) r++;

		int val = b - was;

		int opt = 1e9;
		int g = -1;

		for (int there = 0; there < 2; ++there) {
			if (there == 0 && take.back().first == -1) continue;
			if (there == 1 && take.back().second == -1) continue;

			int Q = last_val - there;
			int delta = val - Q;

			int now = r;
							//cout << now << " " << future << endl;

			while (now < future) {
				//cout << l << " " << r << " " << was << " " << there << " "  << now << endl;
				if (was == 0 && now > r) break;
				if (restricted[now]) {
					now++;
					continue;
				}

				int df = n - now;
				//cout << l << " " << r << " " << was << " " << there << " " << delta << " " << df << " " << now << endl;
				//cout << now << " " << future << " " << delta - df << endl;
				if (delta - df == 0) {
					if (now < opt) {
						opt = now;
						g = there;
					}
					break;
				}
				if (delta - df < 0) {
					now++;
					continue;
				}

				int L = (n-l+1);
				int have = l - take.back().first;
				if (there == 1) have = l - take.back().second;

				//cout << delta-df << " " << L << " " << L+have-1 << " " << possible(delta - df, L, L+have - 1) << endl;

				if (possible(delta - df, L, L+have - 1)) {
					if (now < opt) {
						opt = now;
						g = there;
					}
					break;
				}
				now++;
			}

		}

		if (opt==1e9) opt = -2;

		if (was == 0) {
			res.first = opt+1;
			tres.first = g;
		}
		else {
			res.second = opt+1;
			tres.second = g;
		}

	}

	take.push_back(res);
	trans.push_back(tres);

	last_val = b;

 
}


vector<int> summade(int x, int l, int r) {

	int a = 0, b = r-l+1;
	while (b - a > 1) {
		int c = (a+b)/2;
		if (sum(r-c+1, r) < x) a = c;
		else b = c;
	}

	vector<int> res;
	for (int j = 0; j < b; ++j) {
		res.push_back(l + j);
	}

	for (int i = 0; i < res.size(); ++i) x -= res[i];

	int add = r - res.back();
	int cur = res.size() - 1;
	//cout << add << endl;
	while (x > 0 && x >= add){
		res[cur--] += add;
		x -= add;
	}

		//cout << cur << endl;

	if (cur >= 0) res[cur] += x;
	return res;


	//cout << x << " " << L << " " << R << endl;

}

main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	restricted.assign(n+1, false);

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<pair<int, int> > non_zero;
	for (int i = 0; i < n; ++i) {
		if (v[i] != 0) {
			non_zero.push_back(make_pair(v[i], i));
		}
	}


	if (!non_zero.size()) {
		for (int i = 0; i < n; ++i) cout << 0;
		exit(0);
	}

	take.push_back(make_pair(0, -1));
	trans.push_back(make_pair(-1, -1));

	last_val = 0;

	int start = 0;

	vector<int> what;
	what.push_back(0);

	vector<int> have;
	have.push_back(0);

	while (start < non_zero.size()) {

		int finish = start;
		bool tut = false;
		while (finish < non_zero.size() && non_zero[finish].first <= non_zero[start].first) {
			if (non_zero[finish].first < non_zero[start].first) tut = true;
			else {
				if (tut) break;
			}
			finish++;
		}
		if (finish != non_zero.size()) {
			future = non_zero[finish].second;
			recalc(non_zero, start, finish - 1, false);
		}
		else {
			future = n+1;
			//cout << start << " " << finish << endl;
			if (start == finish-1) recalc(non_zero, start, finish - 1, false);
			else {
				if (non_zero[start].first == non_zero[finish-1].first) {
					for (int i = start; i < finish; ++i) restricted[non_zero[i].second] = true;
					recalc(non_zero, start, start, true);
				}
				else {
					recalc(non_zero, start, finish - 1, false);
				}
			}
		}
		what.push_back(non_zero[finish-1].first);
		have.push_back(n - non_zero[start].second);
		start = finish;
	}

	for (int i = 0; i < take.size(); ++i) {
		//cout << take[i].first << " " << take[i].second << endl;
		//cout << trans[i].first << " " << trans[i].second << endl;
	}

	int cur;

	if (take.back().first <= n+1 && take.back().first != -1) cur = 0;
	else cur = 1;

	string ans;
	for (int i = 0; i < n; ++i) ans += '0';

	for (int i = take.size() - 1; i > 0; i--) {
		int sum = what[i] - cur;
		int last = what[i-1];

		if (cur == 0) {
			last -= trans[i].first;
			if (take[i].first <= n) {
				ans[take[i].first - 1] = '1';
			}

			int delta = sum - last;

			delta -= (n-take[i].first + 1);
			//cout << sum << " " << last << " " << take[i].first-1 << endl;
			//cout << delta << endl;
			int L = have[i] + 1;
			int R;
			if (trans[i].first == 0) R = n - take[i-1].first;
			else R = n - take[i-1].second;
			//cout << delta << endl;
			if (delta > 0) {
				//cout << delta << " === " << L << " " << R << endl;
				vector<int> Q = summade(delta, L, R);
				for (int j = 0; j < Q.size(); ++j){
					ans[n - Q[j]] = '1';
				//	cout << Q[j] << endl;
				}

			}
			cur = trans[i].first;

		}

		else {
			last -= trans[i].second;
			if (take[i].first <= n) ans[take[i].second - 1] = '1';

			int delta = sum - last;

			delta -= (n-take[i].second + 1);
			int L = have[i] + 1;
			int R;
			if (trans[i].second == 0) R = n - take[i-1].first;
			else R = n - take[i-1].second;

			if (delta > 0) {
				//cout << delta << " " << L << " " << R << endl;
				vector<int> Q = summade(delta, L, R);
				for (int j = 0; j < Q.size(); ++j) ans[n - Q[j]] = '1';

			}

			cur = trans[i].second;
		}
	} 

	cout << ans;


}


//////