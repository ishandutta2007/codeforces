#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

const int N = 1e5+5;
int a[N];
int memo[N] = {};
int n;

bool win(int i) {
	if(memo[i] != 0) {
		if(memo[i] == 2) return true;
		else return false;
	}
	bool w = false;
	for(int j = i % a[i]; j < n; j += a[i]) {
		if(a[j] <= a[i]) continue;
		if(!win(j))
			w = true;

	}
	if(w) memo[i] = 2;
	else memo[i] = 1;
	return w;
}

int main() {
	fio;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		if(win(i))
			cout << "A";
		else cout << "B";
	}
	cout << "\n";
}