#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int TT; cin >> TT;
	for(int tt=0;tt<TT;++tt) {
		int n, k, v;
		cin >> n >> k;
		vector<int> beds(n, 0);
		int cnt = 0;
		for(int i=0;i<k;++i) {
			cin >> v;
			beds[--v] = 1;
			++cnt;
		}
		int ops = 1;
		while(cnt < n) {
			for(int i=0;i<n;++i) {
				if(beds[i] == 1) {
					if(i-1 >= 0 && beds[i-1] == 0)
						beds[i-1] = 1, ++cnt;
					if(i+1 < n && beds[i+1] == 0)
						beds[i+1] = 1, ++cnt, ++i;
				}
			}
			++ops;
		}
		cout << ops << endl;
	}
	return 0;
}