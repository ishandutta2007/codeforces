#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

string s;
vector<pair<int, int>>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	bool f = 0;
	for (int i = 0; i < s.size();){
		int j = i;
		i++;
		while (i < s.size() && s[i] == s[i - 1])	i++;
		if (vec.size() && vec.back().second == f)
			vec.back().first += (i - j);
		else
			vec.push_back({i - j, f});
		while (vec.size() && vec.back().first % 2 == 0)
			vec.pop_back();
		f = !f;
	}
	if (vec.size()){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}