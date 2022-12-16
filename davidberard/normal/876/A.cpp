#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<vector<pii>> choices(3);
	choices[0].push_back(pii(1, a));
	choices[0].push_back(pii(2, b));
	choices[1].push_back(pii(0, a));
	choices[1].push_back(pii(2, c));
	choices[2].push_back(pii(0, b));
	choices[2].push_back(pii(1, c));

	n--;
	int total = 0;
	int here=0;
	for(int i=0;i<n;++i) {
		if(choices[here][0].second < choices[here][1].second) {
			total += choices[here][0].second;
			here = choices[here][0].first;
		} else {
			total += choices[here][1].second;
			here = choices[here][1].first;
		}
	}
	
	//asdf a
	cout<< total << endl;
	
	return 0;
}