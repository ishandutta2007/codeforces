#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
string s;
int main() {
	cin >> s;
	int n = s.length();
	if (n == 1 && s[0] == '0') return !printf ("0\n");
	int ret = INT_MAX;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((s[i] == '2' && s[j] == '5') || (s[i] == '5' && s[j] == '0') || (s[i] == '7' && s[j] == '5') || (s[i] == '0' && s[j] == '0')) {
				string ns = s; int k; int att = 0;
				for (k = j; k < n-1; k++) {
					swap(ns[k],ns[k+1]); ++att;
					if (ns[0] == '0') goto ff;
				}
				for (k = i; k < n-2; k++) {
					swap(ns[k],ns[k+1]); ++att;
					if (ns[0] == '0') goto ff;
				}
				ret = min(ret,att);
				ff:;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if ((s[i] == '5' && s[j] == '2') || (s[i] == '0' && s[j] == '5') || (s[i] == '5' && s[j] == '7') || (s[i] == '0' && s[j] == '0')) {
				string ns = s; int k; int att = 0;
				for (k = j; k < n-1; k++) {
					swap(ns[k],ns[k+1]); ++att;
					if (ns[0] == '0') goto fail;
				}
				for (k = i; k < n-2; k++) {
					swap(ns[k],ns[k+1]); ++att;
					if (ns[0] == '0') goto fail;
				}
				ret = min(ret,att+1);
				fail:;
			}
		}
	}
	if (s.size() > 2 && s[1] == '0') {
		int nxt = -1;
		for (int i = 2; i <= n; i++) if (s[i] != '0') {nxt=i; break;}
		int add = 0;
		if (nxt != -1) {
			for (int i = nxt; i >= 2; i--) {
				swap(s[i],s[i-1]);
				++add;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((s[i] == '2' && s[j] == '5') || (s[i] == '5' && s[j] == '0') || (s[i] == '7' && s[j] == '5') || (s[i] == '0' && s[j] == '0')) {
					string ns = s; int k; int att = 0;
					for (k = j; k < n-1; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto fff;
					}
					for (k = i; k < n-2; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto fff;
					}
					ret = min(ret,att+add);
					fff:;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((s[i] == '5' && s[j] == '2') || (s[i] == '0' && s[j] == '5') || (s[i] == '5' && s[j] == '7') || (s[i] == '0' && s[j] == '0')) {
					string ns = s; int k; int att = 0;
					for (k = j; k < n-1; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto ffail;
					}
					for (k = i; k < n-2; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto ffail;
					}
					ret = min(ret,att+1+add);
					ffail:;
				}
			}
		}
		if (nxt != -1) for (int i = 2; i <= nxt; i++) swap(s[i-1],s[i]);
	}
	if (s.size() > 3 && s[2] == '0') {
		swap(s[2],s[3]);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((s[i] == '2' && s[j] == '5') || (s[i] == '5' && s[j] == '0') || (s[i] == '7' && s[j] == '5') || (s[i] == '0' && s[j] == '0')) {
					string ns = s; int k; int att = 0;
					for (k = j; k < n-1; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto ffff;
					}
					for (k = i; k < n-2; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto ffff;
					}
					ret = min(ret,att+1);
					ffff:;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if ((s[i] == '5' && s[j] == '2') || (s[i] == '0' && s[j] == '5') || (s[i] == '5' && s[j] == '7') || (s[i] == '0' && s[j] == '0')) {
					string ns = s; int k; int att = 0;
					for (k = j; k < n-1; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto fffail;
					}
					for (k = i; k < n-2; k++) {
						swap(ns[k],ns[k+1]); ++att;
						if (ns[0] == '0') goto fffail;
					}
					ret = min(ret,att+2);
					fffail:;
				}
			}
		}
	}
	printf ("%d\n",ret>1e9?-1:ret);
    return 0;
}