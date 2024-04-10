#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		printf(s.size() % 2 == 0 && s[0] != ')' && s.back() != '(' ? "Yes\n" : "No\n");
	}
	return 0;
}