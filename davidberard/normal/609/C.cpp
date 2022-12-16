#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	vector<int> a(N);
	vector<int> b(N);
	ll sm = 0;
	for(int& ii: a) {
		cin >> ii;
		sm += ii;
	}
	int base = sm/N;
	int extra = sm-((ll) base)*N;
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	for(int i=0;i<N;++i) {
		b[i] = base;
		if(i < extra) b[i]++;
	}
	ll total = 0;
	for(int i=0;i<N;++i)
		total += abs(a[i]-b[i]);
	cout << total/2 << endl;
	


	return 0;
}