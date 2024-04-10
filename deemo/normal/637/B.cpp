#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

int n;
vector<string>	vec;
map<string, bool>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--){
		string t;	cin >> t;
		vec.push_back(t);
	}
	while (vec.size()){
		if (mp.count(vec.back()) == 0)
			cout << vec.back() << "\n";
		mp[vec.back()] = 1;
		vec.pop_back();
	}
	return	0;
}