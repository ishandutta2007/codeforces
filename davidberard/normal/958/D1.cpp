#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int M; cin >> M;
	regex r("\\(([[:digit:]]+)\\+([[:digit:]]+)\\)\\/([[:digit:]]+)");

	vector<pii> frac;
	map<pii, int> cnt;
	for(int i=0;i<M;++i) {
		string s; cin >> s;
		smatch matches;
		if(regex_search(s, matches, r)) {
			int a = atoi(matches[1].str().c_str());
			int b = atoi(matches[2].str().c_str());
			int c = atoi(matches[3].str().c_str());
			int d = __gcd(a+b, c);
			int num = (a+b)/d;
			int denom = c/d;
			//cerr << a << " " << b << " " << c << " " << d << endl;
			//cerr << " " << num << " " << denom << endl;
			frac.push_back(pii(num, denom));
			if(cnt.count(pii(num, denom)) == 0)
				cnt[pii(num, denom)] = 0;
			++cnt[pii(num, denom)];
		}
	}
	for(int i=0;i<M;++i) {
		cout << cnt[frac[i]] << " ";
	}
	cout << endl;
	return 0;
}