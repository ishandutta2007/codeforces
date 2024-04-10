// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> mapping(256, -1);
vector<bool> fxed(265, false);
int N, K;

void set_mp(int x) {
	int bot = max(x-K+1, 0);
	if(mapping[x] == -1) {
		//cerr << "!!" << endl;
		while(fxed[bot]) {
			++bot;
		}
		//cerr << "Bot = " << bot << endl;
		for(int i=0;i<K;++i) {
			if(bot+i < 256 && (bot+i <= x || mapping[bot+i] == -1)) {
				//cerr << "  " << bot+i << " -> " << bot << endl;
				mapping[bot+i] = bot;
				if(bot+i <= x) {
					fxed[bot+i] = true;
				}
			}
		}
	} else if(!fxed[x]) {
		for(int i=bot;i<=x;++i) {
			fxed[i] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	vector<int> v;
	for(int i=0;i<N;++i) {
		int val;
		cin >> val;
		set_mp(val);
		v.push_back(val);
	}
	for(int vv : v ) {
		cout << mapping[vv] << " ";
	}
	cout << endl;
	
	return 0;
}