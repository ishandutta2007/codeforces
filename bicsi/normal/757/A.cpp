#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump() cerr<<"OK!\n"

int F1[256], F2[256];
void make(string s, int To[]) {
	for(auto c : s)
		To[c] += 1;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	string s;
	cin >> s;

	string bulb = "Bulbasaur";
	make(s, F1);
	make(bulb, F2);

	int ans = 500000;
	for(int c = 0; c < 256; ++c) {
		if(F2[c] == 0) continue;
		ans = min(ans, F1[c] / F2[c]);
	}
	cout << ans << endl;

	return 0;
}