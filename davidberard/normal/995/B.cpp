#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;
	vector<int> a(N*2);
	for(auto& ii : a) cin >> ii;
	int ans = 0;
	for(int i=0;i<N*2;i+=2) {
		int pos = -1;
		for(int j=i+1;j<N*2;++j) {
			if(a[j] == a[i]) {
				pos = j;
				break;
			}
		}
		//cerr << " at " << pos << endl;
		for(int j=pos-1;j>i;--j) {
			swap(a[j], a[j+1]);
			++ans;
		}
	}
	//cerr;for(int i=0;i<N;++i) {
		//cerr << a[i] << " ";
	//cerr;} //cerr << endl;

	cout << ans << endl;

	return 0;
}