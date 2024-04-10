#include <bits/stdc++.h>
using namespace std;

int n, k;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	return true;
}

void solve() {
	bool win = true;
	if(k % 3 == 0) {
		int np = n % (k + 1);
		if(np % 3 == 0 && np != k)
			win = false;
	} else {
		int np = n % 3;
		if(np == 0)
			win = false;
	}
	
	puts(win ? "Alice" : "Bob");
}

int main(){
	int T; cin >> T;
	while(T--) {
		read();
		solve();
	}
	return 0;
}