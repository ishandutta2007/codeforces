#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

/*map<pair<int, ll>, int> mp;

int go(int rem, ll mask){
	if (mp.count({rem, mask})) return mp[{rem, mask}];
	vector<int> vec;
	for (int i = 1; i <= rem; i++)
		if (!(mask>>i&1))
			vec.push_back(go(rem-i, mask^1ll<<i));
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] != i)
			return mp[{rem, mask}] = i;
	return mp[{rem, mask}] = vec.size();
}*/

int gr[61] = {0, 1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//for (int i = 1; i <= 60; i++)
	//	cout << go(i, 0ll) << ",";
	//cout << "\n";
	int n;	cin >> n;
	int x = 0;
	while (n--){
		int temp;	cin >> temp;
		x ^= gr[temp];
	}
	if (x)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}