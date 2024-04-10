#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<map>

using namespace std;

const int MAXN = 1e5 + 10;

int n, m;
map<int, int>	mp;
vector<int>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (n--){
		int x;	cin >> x;
		mp[x] = 1;
	}
	int sm = 0;
	for (int i = 1; sm + i <= m; i++)
		if (mp.count(i) == 0){
			sm += i;
			vec.push_back(i);
		}
	cout << vec.size() << "\n";
	for (auto v:vec)
		cout << v << " ";
	cout << "\n";
	return	0;
}