/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll MOD = 1e9 + 7;

struct line {
	int a, b, i;
};

bool operator < (line a, line b) {
	return a.a * b.b < a.b * b.a;
}

bool operator == (line a, line b) {
	return (!(a < b)) && (!(b < a));
}

int to_int(string s) {
	int res = 0, p = 1;
	for (int i = s.size() - 1; i >= 0; --i) {
		res += (s[i] - '0') * p;
		p *= 10;
	}
	return res;
}

line parse(string s, int pos) {
	int dpos;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '/')
			dpos = i;
	}
	string s1, s2;
	s1 = s.substr(1, dpos - 2);
	s2 = s.substr(dpos + 1, n - dpos - 1);
	int ppos;
	int m = s1.size();
	for (int i = 0; i < m; ++i) {
		if (s1[i] == '+')
			ppos = i;
	}
	string s3, s4;
	s3 = s1.substr(0, ppos);
	s4 = s1.substr(ppos + 1, m - 1 - ppos);
	return {to_int(s3) + to_int(s4), to_int(s2), pos};
}

const int mx = 3e5;
int n, ans[mx];
vector<line> a;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a.push_back(parse(s, i));
	}
	sort(a.begin(), a.end());
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] == a[i - 1]) {
			cnt++;
			continue;
		}
		for (int j = i - 1; j >= i - cnt; --j) {
			ans[a[j].i] = cnt;
		}
		cnt = 1;
	}
	for (int j = n - 1; j >= n - cnt; --j) {
		ans[a[j].i] = cnt;
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}