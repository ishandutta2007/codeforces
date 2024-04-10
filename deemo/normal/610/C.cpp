#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int k;
vector<string>	vec;

string rev(string s){
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '+')
			s[i] = '*';
		else
			s[i] = '+';
	return	s;
}

int main(){
	cin >> k;
	if (k == 0){
		cout << "+\n";
		return 0;
	}
	vec.push_back("+");
	for (int i = 1; i <= k; i++){
		int sz = vec.size();
		for (int j = 0; j < sz; j++){
			string temp = rev(vec[j]);
			vec.push_back(vec[j] + temp);
			vec[j] += vec[j];
		}
	}
	for (string s:vec)
		cout << s << "\n";
	return 0;
}