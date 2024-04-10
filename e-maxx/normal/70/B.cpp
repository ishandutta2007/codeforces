#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	vector<string> t;
	string p;
	for (string w; cin >> w; ) {
		if (p.empty())
			p = w;
		else
			p += " " + w;
		if (string(".?!").find(w[w.length()-1]) != -1) {
			t.push_back (p);
			if ((int)p.length() > n) {
				cout << "Impossible";
				return 0;
			}
			p = "";
		}
	}

	int ans = 0;
	string cur;
	for (size_t i=0; i<t.size(); ++i) {
		string ncur = cur;
		if (cur.length())  ncur += " ";
		ncur += t[i];

		if ((int)ncur.length() > n) {
			++ans;
			cur = t[i];
		}
		else
			cur = ncur;
	}
	if (cur.length())
		++ans;
	cout << ans;

}