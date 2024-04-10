//sytxdy
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <ctime>

using namespace std;


#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define NMAX 105

string name[NMAX], body[NMAX];
int n;
string s;
int d[NMAX];
map<string, int> macro_id;

int add(string& s, int& ptr);

void go(int k);

int un(string& s, int& ptr) {
	if (s[ptr] == '(') {
		ptr++;
		int r = add(s, ptr);
		if (r & 2) r ^= 2;
		if (r & 4) r ^= 4;
		ptr++;
		return r;
	}

	string id = "";
	while (ptr < s.size() && (isalpha(s[ptr]) || isdigit(s[ptr]))) {
		id += s[ptr++];
	}

	if (macro_id.count(id)) {
		int k = macro_id[id];
		go(k);
		return d[k];
	} else {
		return 0;
	}
}

int mul(string& s, int& ptr) {
	int ret = un(s, ptr);
	int cnt = 1;
	char last_op = '*';

	bool f = true;

	while (ptr < s.size() && (s[ptr] == '*' || s[ptr] == '/')) {
		if (f && (ret & 2)) {
			ret |= 1;
		}

		f = false;

		last_op = s[ptr];
		ptr++;
		int next = un(s, ptr);

		if (next & 4) ret |= 4;
		if (next & 1) ret |= 1;
		if (next & 2) ret |= 1;
		if (last_op == '/' && (next & 4)) ret |= 1;
		cnt++;
	}

	if (cnt > 1) ret |= 4;

	return ret;
}

int add(string& s, int& ptr) {
	int ret = mul(s, ptr);
	int cnt = 1;
	char last_op = '+';

	while (ptr < s.size() && (s[ptr] == '+' || s[ptr] == '-')) {
		last_op = s[ptr];
		ptr++;
		int next = mul(s, ptr);

		if (next & 2) ret |= 2;
		if (next & 1) ret |= 1;
		if (last_op == '-' && (next & 2)) ret |= 1;
		cnt++;
	}

	if (cnt > 1) {
		if (ret & 4) ret ^= 4;
		ret |= 2;
	}

	return ret;
}

void go(int k) {
	if (d[k] != -1) {
		return;
	}
	string str = body[k];

	int ptr = 0;

	int code = add(str, ptr);

	d[k] = code;
}

int main() {
	scanf("%d\n", &n);
	forn(i, n) {
		getline(cin, s);
		while (s[0] == ' ') s.erase(0, 1);
		s.erase(0, 1);
		while (s[0] == ' ') s.erase(0, 1);
		s.erase(0, 7);
		while (s[0] == ' ') s.erase(0, 1);

		int p = s.find(' ');
		name[i] = s.substr(0, p);
		s.erase(0, p + 1);

		forv(j, s) {
			if (s[j] != ' ') {
				body[i] += s[j];
			}
		}

		macro_id[name[i]] = i;
	}
	getline(cin, s);
	forv(j, s) {
		if (s[j] != ' ') {
			body[n] += s[j];
		}
	}

	forn(i, n + 1) {
		d[i] = -1;
	}

	go(n);

	if (d[n] & 1) {
		printf("Suspicious\n");
	} else {
		printf("OK\n");
	}

	return 0;
}