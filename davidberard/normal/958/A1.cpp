#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool equal(const vector<string>& v, const vector<string>& w) {
	for(int i=0;i<v.size();++i) {
		if(v[i] != w[i]) {
			return false;
		}
	}
	return true;
}

vector<string> rotate(const vector<string>& v) {
	vector<string> w(v);
	int N = w.size();
	for(int i=0;i<N;++i) {
		for(int j=0;j<N;++j) {
			w[j][N-i-1] = v[i][j];
		}
	}
	return w;
}

vector<string> flip(const vector<string>& v) {
	vector<string> w(v);
	for(int i=0;i<v.size();++i) {
		reverse(w[i].begin(), w[i].end());
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	string s;
	vector<string> v(N), w(N);
	for(string& ss : v) cin >> ss;
	for(string& ss : w) cin >> ss;

	if(equal(v, w) || equal(v, rotate(w)) || equal(v, rotate(rotate(w))) || equal(v, rotate(rotate(rotate(w))))
	|| equal(v, flip(w)) || equal(v, rotate(flip(w))) || equal(v, rotate(rotate(flip(w)))) || equal(v, rotate(rotate(rotate(flip(w))))) ) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}