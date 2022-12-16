#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	set<int> s;
	int N, v;
	cin >> N;
	for(int i=0;i<N;++i) {
		cin >> v;
		if(v != 0)
			s.insert(v);
	}
	cout << s.size() << endl;
	return 0;
}
// David Berard