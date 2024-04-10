#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s;
vector<int>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	if (s.size() == 1){
		cout << "No" << endl;
		return 0;
	}
	
	int cnt = 0;
	for (int i = 0; i < s.size(); i++){
		if (cnt == 0 || s[i] == s[i - 1]){
			cnt++;
			continue;
		}
		if (cnt % 2 == 1){
			vec.push_back(cnt);
			cnt = 1;
			continue;
		}
		if (vec.size()){
			cnt = vec.back() + 1;
			vec.pop_back();
			continue;
		}
		cnt = 1;
	}
	if (cnt % 2 == 1){
		cout << "No" << endl;
		return 0;
	}
	vec.size()?cout<<"No\n": cout<<"Yes\n";
	return 0;
}