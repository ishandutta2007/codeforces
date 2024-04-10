#include <iostream>
#include <vector>
#include <string>

using namespace std;

int f(int k, const string& s, int pos = 0, int offset = 0, vector<int>* ans = nullptr, vector<int>* l = nullptr, vector<int>* r = nullptr) {
	if (pos > s.length())
		return pos;

	if (k <= 1) {
		if (ans != nullptr)
			(*ans)[offset] = 0;
		return pos;
	} else {
		int L = k / 2;
		int R = k - L;
		pos = f(L, s, pos, offset, ans, l, r);
		pos = f(R, s, pos, offset + L, ans, l, r);
		if (ans != nullptr) {
			for (int i = 0; i < L; ++i)
				(*l)[(*ans)[i + offset]] = i;
			for (int i = 0; i < R; ++i)
				(*r)[(*ans)[i + L + offset]] = i;
		}
		int li = 0, ri = 0;
		while (li < L and ri < R and pos < s.length()) {
			if (s[pos++] == '0') {
				//cerr << "L" << endl;
				if (ans != nullptr)
					(*ans)[offset + (*l)[li]] = li + ri; 
				++li;
			} else {
				//cerr << "R" << endl;
				if (ans != nullptr)
					(*ans)[offset + L + (*r)[ri]] = li + ri; 
				++ri;
			}
		}
		if (pos == s.length() and li != L and ri != R)
			return pos + 1;
		while (li != L)
		{
			if (ans != nullptr)
				(*ans)[offset + (*l)[li]] = li + ri; 
			++li;
		}
		while (ri != R)
		{
			if (ans != nullptr)
				(*ans)[offset + L + (*r)[ri]] = li + ri; 
			++ri;
		}	
	}
	return pos;
}

void solve() {
	string s; cin >> s;
	int l = 1, r = 1 << 20;
	while (r - l > 1) {
		int m = (l + r) / 2;
		int need = f(m, s);
		if (need > s.length())
			r = m;
		else
			l = m;
	}
	vector<int> ans(l), left(l), right(l);
	f(l, s, 0, 0, &ans, &left, &right);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << ' ';
		cout << ans[i] + 1;
	}
	cout << endl;
}

int main() {
	solve();
	return 0;
}