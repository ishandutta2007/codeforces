#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, int> buy, sell;
	int n, s;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		string direction;
		int price, volume;
		cin >> direction >> price >> volume;
		if(direction == "S") sell[price] += volume;
		else buy[price] += volume;
	}
	while(sell.size() > s) sell.erase(sell.rbegin()->first);
	while(buy.size() > s) buy.erase(buy.begin()->first);

	for(auto it = sell.rbegin(); it != sell.rend(); ++it) {
		cout << "S " << it->first << ' ' << it->second << endl;	
	}
	for(auto it = buy.rbegin(); it != buy.rend(); ++it) {
		cout << "B " << it->first << ' ' << it->second << endl;
	}
	return 0;
}