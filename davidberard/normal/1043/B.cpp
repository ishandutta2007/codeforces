#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	vector<int> ans;
	int N;
	cin >> N;
	vector<int> a(N);
	for(auto& x : a) cin >> x;

	for(int l=1;l<=N;++l) {
		bool good = true;
		vector<int> xv;
		//cerr << " l = " << l << endl;
		for(int i=0;i<l;++i) {
			if(i == 0) xv.push_back(a[i]);
			else xv.push_back(a[i]-a[i-1]);
			//cerr << " added "<< xv.back() << " l = " << l << endl;
		}
		for(int i=l;i<N;++i)
		{
			if(a[i]-a[i-1] != xv[(i)%l]) {
				//cerr << " expected " << a[i] << " - " << a[i-1] << " == " << xv[i%l] << " at index " << i%l << " of " << xv.size() << " l = " << l << endl;
				good = false;
				break;
			}
		}
		if(!good) continue;
		ans.push_back(l);
	}
	cout << ans.size() << endl;
	for(auto& x : ans) cout << x << " ";
	cout << endl;

	return 0;
}