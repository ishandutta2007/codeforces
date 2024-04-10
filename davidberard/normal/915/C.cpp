#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ld;

inline vector<int> ullToVec(ull u) {
	vector<int> v;
	while(u > 0) {
		v.push_back(u%10);
		u /= 10;
	}
	reverse(v.begin(), v.end());
	return v;
}
inline ull vecToUll(vector<int> v) {
	ull o=0;
	for( int i : v) {
		o = o*10+i;
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	ull a, b;
	cin >> a >> b;

	vector<int> va = ullToVec(a);
	sort(va.begin(), va.end());

	vector<int> curr;
	
	for(int i=0;i<va.size();++i) {
		int j;
		curr.push_back(va[i]);
		for(j=i+1;j<va.size();++j)
			curr.push_back(va[j]);

		
		bool exceeds = false;
		for(j=i+1;j<va.size();++j) {
			int vv = curr[i];
			for(int k=i;k<va.size()-1;++k) {
				curr[k+1] = va[k + (k >= j) ];
			}
			curr[i] = va[j];
			exceeds = vecToUll(curr) > b;
			for(int k=i;k<va.size()-1;++k) {
				curr[k+1] = va[k+1];
			}
			curr[i] = vv;
			if(exceeds)
				break;
		}
		if(j-1 == i) { 
			for(j=va.size()-2;j>=i;--j) {
				curr.pop_back();
			}
			continue;
		}
			int vv = curr[i];
			for(int k=i;k<va.size()-1;++k) {
				curr[k+1] = va[k + (k >= j-1) ];
			}
			curr[i] = va[j-1];
		for(int k=i+1;k<va.size();++k)
			va[k] = curr[k];
		for(j=va.size()-2;j>=i;--j) {
			curr.pop_back();
		}
		sort(va.begin()+i+1, va.end());
	}

	for(int i=0;i<curr.size();++i) {
		cout << curr[i];
	}
	cout << endl;
	
	return 0;
}