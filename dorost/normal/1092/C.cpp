/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
string a[N * 2];
int n;

bool is(string s) {
	map <string, int> mp;
	for (int i = 0; i < n * 2 - 2; i++) {
		mp[a[i]]++;
	}
	string t;
	for (int i = 0; i < s.size() - 1; i++) {
		t += s[i];
		if (!mp[t])
			return false;
		mp[t]--;
	}
	t = "";
	for (int i = s.size() - 1; i > 0; i--) {
		t = s[i] + t;
		if (!mp[t])
			return false;
		mp[t]--;
	}
	return true;
}

void print(string s) {
	map <string, vector <int>> mp;
	string r;
	for (int i = 0; i < n * 2 - 2; i++) {
		r += "|";
		mp[a[i]].push_back(i);
	}
	string t;
	for (int i = 0; i < s.size() - 1; i++) {
		t += s[i];
		r[mp[t].back()] = 'P';
		mp[t].pop_back();
	}
	t = "";
	for (int i = s.size() - 1; i > 0; i--) {
		t = s[i] + t;
		r[mp[t].back()] = 'S';
		mp[t].pop_back();
	}
	cout << r;
}

int32_t main() {
	cin >> n;
	string s, t, r, e;
	for (int i = 0; i < n * 2 - 2; i++) {
		cin >> a[i];
		if (a[i].size() == n - 1) {
			if (s.size())
				t = a[i];
			else
				s = a[i];
		} 
		if (a[i].size() == 1) {
			if (r.size())
				e = a[i];
			else
				r = a[i];
		}
	}
	if (is(s + e)) {
		print(s + e);
	} else if (is(s + r)) {
		print(s + r);
	} else if (is(r + s)) {
		print(r + s);
	} else if(is(e + s)) {
		print(e + s);
	} else if (is(t + e)) {
		print(t + e);
	} else if (is(t + r)) {
		print(t + r);
	} else if (is(r + t)) {
		print(r + t);
	} else if(is(e + s)) {
		print(e + t);
	}
}