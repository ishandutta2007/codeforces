#include <bits/stdc++.h>

using namespace std;

bool compare(int v, int m) {
	switch(m%12) {
		case 0: case 2: case 4: case 6: case 7: case 9: case 11: return (v == 31);
		case 3: case 5: case 8: case 10: return (v == 30);
		case 1: return (v == 29 || v == 28);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N;
	cin >> N;

	bool seen = false;
	bool bad = false;
	vector<int> d(N);
	for(int i=0;i<N && !bad;++i) {
		cin >> d[i];
		if(d[i] == 29) {
			if(!seen) seen = true;
			else bad = true;
		}
	}
	
	bool good = false;
	for(int i=0;i<12 && !bad && !good;++i) {
		bool shit = false;
		for(int j=0;j<N && !shit;++j) {
			shit = shit || !compare(d[j], i+j);
			//cerr << shit << "(" << d[j] <<"," << i+j<< ") ";
		}
		//cerr << endl;
		if(!shit) good = true;
	}

	if(good) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}