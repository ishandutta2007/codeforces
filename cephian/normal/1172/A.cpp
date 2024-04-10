#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 2e5+5;
int ob[N], b[N], oloc = -1, n;

int without() {
	if(oloc == -1) return -1;
	int i = 1;
	for(; oloc-1 + i < n; ++i) {
		if(b[oloc-1+i] != i) return -1;
	}
	int shift = i;
	for(; i <= n; ++i) {
		if(ob[i] > i-shift)
			return -1;
	}
	return n - shift + 1;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if(a) ob[a] = 0;
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		if(b[i]) ob[b[i]] = i+1;
		if(b[i] == 1)
			oloc = i;
	}
	int x = without();
	if(x != -1) {
		cout << x << "\n";
		return 0;
	}

	int worst = 0;
	for(int i = 1; i <= n; ++i) {
		worst = max(worst, ob[i] - (i-1));
	}
	cout << worst + n << "\n";
}