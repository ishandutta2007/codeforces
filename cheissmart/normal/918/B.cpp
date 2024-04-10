#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, string> mp;
	int n, m;
	string name, ip;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> name >> ip;
		mp[ip+';'] = name;
	}
	for(int i=0;i<m;i++) {
		string name, ip;
		cin >> name >> ip;
		cout << name << " " << ip << " #" << mp[ip] << endl;
	}
}