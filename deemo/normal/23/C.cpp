#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 3e5 + 20;

int n;
set<pair<pair<int, int>, int>>	ss, tt;
pair<int, int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		cout << "YES\n";
		ss.clear();
		tt.clear();

		cin >> n;	n = 2 * n - 1;
		for (int i = 0; i < n; i++){
			cin >> vec[i].first >> vec[i].second;
			ss.insert({vec[i], i});
			tt.insert({{vec[i].second, vec[i].first}, i});
		}
		for (int i = 0; i < n; i++){
			if (i % 4 == 0){
				auto it = ss.end();	it--;
				cout << it->second + 1 << " ";
				tt.erase({{it->first.second, it->first.first}, it->second});
				ss.erase(it);
			}
			if (i % 4 == 1){
				auto it = tt.end();	it--;
				cout << it->second + 1 << " ";
				ss.erase({{it->first.second, it->first.first}, it->second});
				tt.erase(it);
			}
			if (i % 4 == 2){
				auto it = ss.begin();
				tt.erase({{it->first.second, it->first.first}, it->second});
				ss.erase(it);
			}
			if (i % 4 == 3){
				auto it = tt.begin();
				ss.erase({{it->first.second, it->first.first}, it->second});
				tt.erase(it);
			}
		}
		cout << "\n";
	}
	return	0;
}