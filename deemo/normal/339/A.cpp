#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	string s;	vector<int>	vec;
	cin >> s;
	for (int i = 0; i < s.size(); i += 2)
		vec.push_back(s[i] - 48);
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i];
		if (i != vec.size() - 1)	cout << "+";
	}
	cout << endl;
	return 0;
}