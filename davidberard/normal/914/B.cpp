#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N;
	map<int, int> mp;
	cin >> N;
	int v;
	for(int i=0;i<N;++i) {
		cin >> v;
		if(mp.count(v) == 0)
			mp[v]=0;
		mp[v]++;
	}

	int winner = 0;
	for(auto it = mp.rbegin(); it != mp.rend();++it) {
		if(it->second%2 == 1) {
			winner = 1;
			break;
		}
	}
	if(winner)
		cout << "Conan" << endl;
	else
		cout << "Agasa" << endl;



	return 0;
}