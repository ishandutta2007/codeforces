#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int n,m;
vector<string> r[10005][805];
vector<vector<string> > res;
vector<vector<int> > rs;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		string name;
		int reg,score;
		cin >> name >> reg >> score;
		r[reg][score].push_back(name);
	}
	res.push_back(vector<string>());
	rs.push_back(vector<int>());
	for(int reg = 1; reg <= m; ++reg) {
		res.push_back(vector<string>());
		rs.push_back(vector<int>());
		for(int score = 800; score >=0; --score) {
			for(int k = 0; k < r[reg][score].size(); ++k) {
				if(res[reg].empty()) {
					res[reg].push_back(r[reg][score][k]);
				} else if(res[reg].size() == 1) {
					res[reg].push_back(r[reg][score][k]);
				} else {
					if(rs[reg][1] == score) {
						cout << "?\n";
						goto skp2;
					} else {
						goto skp;
					}
				}
				rs[reg].push_back(score);
			}
		}
		skp:;
		cout << res[reg][0] << " " << res[reg][1] << "\n";
		skp2:;
	}
	return 0;
}