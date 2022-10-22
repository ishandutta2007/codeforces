#include<iostream>
#include<map>
#include<string>
#include<sstream>

using namespace std;

map<string, int>	mp;
int n;

string append(string t, int x){
	stringstream ss;
	ss << x;
	return t + ss.str();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while (n--){
		string t;
		cin >> t;
		if (mp[t] == 0){
			mp[t]++;
			cout << "OK\n";
			continue;
		}
		cout << append(t, mp[t]) << '\n';
		mp[t]++;
	}
	return 0;
}