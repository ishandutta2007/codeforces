#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	map<int, int> mp;
	int v;
	for(int i=0;i<n;++i) {
		cin >> v;
		if(mp.count(v) == 0)
			mp[v] = 0;
		mp[v] ++;
	}
	vector<int> vals;
	vector<int> amts;
	for(const auto& it : mp) {
		vals.push_back(it.first);
		amts.push_back(it.second);
	}
	if(vals.size() == 2 && vals[0]+1 != vals[1]) {
		vals.push_back(vals[1]-1);
		swap(vals[1], vals[2]);
		amts.push_back(amts[1]);
		amts[1] = 0;
	}
	if(vals.size() == 1) {
		cout << n << endl;
		for(int i=0;i<amts[0];++i)
			cout << vals[0] << " ";
		cout << endl;
	} else if(vals.size() == 2) {
		cout << n << endl;
		for(int i=0;i<amts[0];++i)
			cout << vals[0] << " ";
		for(int i=0;i<amts[1];++i)
			cout << vals[1] << " ";
		cout << endl;
	} else if(vals.size() == 3) {
		if((amts[1]/2)*2 > min(amts[0],amts[2])*2) {
			cout << amts[0] + amts[2] + (amts[1]%2) << endl;
			for(int i=0;i<amts[0];++i)
				cout << vals[0] << " ";
			for(int i=0;i<amts[2];++i)
				cout << vals[2] << " ";
			for(int i=0;i<amts[1]/2;++i)
				cout << vals[0] << " " << vals[2] << " ";
			if(amts[1]%2) cout << vals[1];
		} else {
			cout << amts[1] + max(amts[0], amts[2]) - min(amts[0], amts[2]) << endl;  
			for(int i=0;i<amts[0]-min(amts[0], amts[2]);++i)
				cout << vals[0] << " ";
			for(int i=0;i<amts[2]-min(amts[0], amts[2]);++i)
				cout << vals[2] << " ";
			for(int i=0;i<amts[1]+2*min(amts[0], amts[2]);++i)
				cout << vals[1] << " ";
		}
		cout << endl;
	}
	return 0;
}