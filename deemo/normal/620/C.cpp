#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 20;

int n, vec[MAXN];
vector<pair<int, int>>	ans;
map<int, int>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	bool fl = 1;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		mp[vec[i]]++;
		if (mp[vec[i]] > 1)	fl = 0;
	}
	if (fl){
		cout << -1 << endl;
		return	0;
	}

	mp.clear();
	int b = 0;
	for (int i = 0; i < n; i++){
		mp[vec[i]]++;
		if (mp[vec[i]] == 2){
			mp.clear();
			ans.push_back({b, i});
			b = i + 1;
		}
	}
	if (b != n)
		ans.back().second = n - 1;


	cout << ans.size() << endl;
	for (pair<int, int>	v:ans)
		cout << v.first + 1 << " " << v.second + 1 << "\n";
	return	0;
}