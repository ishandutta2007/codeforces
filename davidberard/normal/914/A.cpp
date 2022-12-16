#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N;
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;++i) cin >> a[i];
	sort(a.begin(), a.end());
	int best = -1;
	for(int i=0;i<N;++i) {
		if(a[i] < 0) best = i;
		else {
			ld rt = sqrt((ld) a[i]) + 1e-9;
			if( ((int) (rt) )*((int) (rt)) != a[i]) {
				//cerr << "!! " << ((int) (rt))*((int) (rt)) << " :: " <<  a[i] << endl;
				best = i;
			}
		}
	}
		cout << a[best] << endl;


	return 0;
}