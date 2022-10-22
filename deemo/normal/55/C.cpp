//Here we go again..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	bool win = 0;
	while (k--){
		int a, b;	cin >> a >> b;
		if (n + 1 - a <= 5)	win = 1;
		if (m + 1 - b <= 5)	win = 1;
		if (a <= 5)	win = 1;
		if (b <= 5)	win = 1;
	}
	if (win)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}