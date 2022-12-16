#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef complex<ld> pt;

int N;
int cnt;
vector< stack<int> > fe;

int getNext(int start) {

	for(int i=start;i<N;++i) {
		if(fe[i].size() > 0) {
			int res = fe[i].top();
			fe[i].pop();
			--cnt;
			return res;
		}
	}
	return N;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	fe.resize(N);
	cnt = 0;
	for(int i=0;i<N;++i) {
		for(int j=N;j>i;--j) {
			fe[i].push(j);
			++cnt;
		}
	}

	int layer = 0;
	while(cnt > 0) {
		int pos = 0;
		while(pos < N) {
			pos = getNext(pos);
		}
		++layer;
	}

	cout << layer << endl;
	
	
	
	return 0;
}