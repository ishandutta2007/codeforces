#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	vector<int> start(M+1, 0), end(M+1, 0);
	for(int i=0;i<N;++i) {
		int a, b;
		cin >> a >> b;
		start[a] ++;
		end[b] ++;
	}
	bool bad = false;
	int amt = 0;
	for(int i=0;i<=M && !bad;++i) {
		amt += start[i];
		amt -= end[i];
		if(amt == 0 && i != M) {
			bad = true;
		}
	}

	if(bad) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	
	return 0;
}