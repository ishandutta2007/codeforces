#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

vector<string>	vec;

bool cmp(string a, string b){
	if (a.size() < b.size())	return	true;
	if (b.size() < a.size())	return	false;
	return	a < b;
}

int main(){
	string temp;
	for (char c = 'a'; c <= 'z'; c++){
		temp = c;
		vec.push_back(temp);
	}
	for (char c = 'a'; c <= 'z'; c++)
		for (char b = 'a'; b <= 'z'; b++){
			temp = c;
			temp += b;
			vec.push_back(temp);
			for (char a = 'a'; a <= 'z'; a++){
				temp = c;
				temp += b;
				temp += a;
				vec.push_back(temp);
			}
		}
	sort(vec.begin(), vec.end(), cmp);

	int n;	cin >> n;
	vector<string>	sec(n);
	for (int i = 0; i < n; i++)	cin >> sec[i];

	for (string s:vec){
		bool fl = 1;
		for (int i = 0; i < n; i++)
			if (sec[i].find(s) != sec[i].npos){
				fl = 0;
				break;
			}
		if (fl){
			cout << s << endl;
			return 0;
		}
	}

	return 0;
}