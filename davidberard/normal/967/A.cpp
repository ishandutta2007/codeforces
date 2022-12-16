#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void print_time(int h, int m) {
	int nh = h + m/60;
	int nm = m%60;
	cout << nh << " " << nm << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, S; cin >> N >> S;
	int lh = 0, lm = -S-1;
	for(int i=0;i<N;++i) {
		int h, m;
		cin >> h >> m;
		if((h-lh)*60+(m-lm) >= 2*(S+1)) {
			print_time(lh, lm+S+1);
			return 0;
		}
		lh = h;
		lm = m;
	}
	print_time(lh, lm+S+1);
	
	return 0;
}