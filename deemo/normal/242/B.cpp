#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

pair<int, int>	vec[MAXN];
map<pair<int, int>, int>	mp;

bool cmp(pair<int, int>	a, pair<int, int>	b){
	if (a.first != b.first)
		return	a.first < b.first;
	return	a.second > b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	int maxi = -1e9 - 2;
	for (int i = 0; i < n; i++){
		int l, r;	cin >> l >> r;	mp[{l, r}] = i + 1;
		vec[i] = {l, r};
		maxi = max(maxi, r);
	}
	sort(vec, vec + n, cmp);
	if (vec[0].second == maxi)
		cout << mp[vec[0]] << endl;
	else
		cout << -1 << endl;
	return 0;
}