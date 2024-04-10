#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++){
		int val;	string s;	cin >> val >> s;
		if (s == "South")
			x += val;
		else if (s == "North")
			x -= val;
		else if (s == "East"){
			y += val;
			if (x == 0 || x == 20000){
				cout << "NO\n";
				return 0;
			}
		}
		else if (s == "West"){

			y -= val;

			if (x == 0 || x == 20000){
				cout << "NO\n";
				return 0;
			}
		}
		if (x < 0 || x > 20000){
			cout << "NO\n";
			return 0;
		}
	}
	if (x){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	return 0;
}