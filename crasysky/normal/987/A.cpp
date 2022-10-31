#include <iostream>
#include <string>
#include <map>
using namespace std;
map <string, int> mp;
string turn[10];
bool have[10];
int main(){
	mp["purple"] = 1;
	mp["green"] = 2;
	mp["blue"] = 3;
	mp["orange"] = 4;
	mp["red"] = 5;
	mp["yellow"] = 6;

	turn[1] = "Power";
	turn[2] = "Time";
	turn[3] = "Space";
	turn[4] = "Soul";
	turn[5] = "Reality";
	turn[6] = "Mind";
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		string s;
		cin >> s;
		have[mp[s]] = true;
	}
	int cnt = 0;
	for (int i = 1; i <= 6; ++ i)
		if (! have[i])
			++ cnt;
	cout << cnt << endl;
	for (int i = 1; i <= 6; ++ i)
		if (! have[i])
			cout << turn[i] << endl;
}
/*
6
purple
green
blue
orange
red
yellow
*/