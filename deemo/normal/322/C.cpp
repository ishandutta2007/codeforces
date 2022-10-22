#include<iostream>
#include<string>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int a, b;	cin >> a >> b;
	string s;	cin >> s;
	vector<pair<int, int>>	vec;
	vec.push_back({0, 0});
	int x = 0, y = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'U')	y++;
		if (s[i] == 'D')	y--;
		if (s[i] == 'L')	x--;
		if (s[i] == 'R')	x++;
		vec.push_back({x, y});
	}

	bool fl = 0;
	for (pair<int, int>	v:vec){
		int f = abs(a - v.first), g = abs(b - v.second);
		if (f == g && f == 0){
			fl = 1;
			break;
		}
		if (x == 0 && y == 0)	continue;
		int z;
		if (x != 0)	z = abs(f/x);
		else	z = abs(g/y);
		v.first += z * x;
		v.second += z * y;
		if (v.first == a && v.second == b)	fl = 1;
	}
	if (fl)	cout << "Yes" << endl;
	else	cout << "No" << endl;
	return 0;
}