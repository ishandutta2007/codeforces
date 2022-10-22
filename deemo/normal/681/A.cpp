#include<iostream>
#include<string>

using namespace std;

int main(){
	int n;	cin >> n;
	bool ans = 0;
	while (n--){
		string temp;	int x, y;	
		cin >> temp >> x >> y;
		if (y > x && x >= 2400)
			ans = 1;
	}
	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}