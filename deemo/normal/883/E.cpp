
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int maxn = 1005;

vector <char> alpha;

bool seen[maxn], mark[maxn], has[maxn];
string s, t;

int main(){
	for (char c = 'a'; c <= 'z'; c++) alpha.pb(c);
	for (char c = 'A'; c <= 'Z'; c++) alpha.pb(c);
	for (char c = '0'; c <= '9'; c++) alpha.pb(c);
	int n = in();
	cin >> s;
	for (int i = 0; i < n; i++)
		if (s[i] != '*')
			seen[s[i]] = true;
	for (char c : alpha)
		if (!seen[c])
			has[c] = true;
	int m = in();
	for (int i = 0; i < m; i++){
		cin >> t;
		bool ok = true;
		for (char c : alpha)
			mark[c] = false;
		for (int j = 0; j < n; j++){
			if (s[j] == '*'){
				ok &= !seen[t[j]];
				mark[t[j]] = true;
			}
			else
				ok &= (t[j] == s[j]);
		}
		if (ok){
			for (char c : alpha)
				has[c] &= mark[c];
		}
	}
	int cnt = 0;
	for (char c : alpha)
		if (has[c])
			cnt++;
	cout << cnt << endl;
	return 0;
}