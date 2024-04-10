#include<iostream>
#include<string>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;	cin >> a >> b;
	if (a.size() != b.size()){
		cout << "NO\n";
		return 0;
	}

	int ca = 0, cb = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == '1')	ca++;
	for (int i = 0; i < b.size(); i++)
		if (b[i] == '1')	cb++;
	if ((ca == 0) ^ (cb == 0))
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}