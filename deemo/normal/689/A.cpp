#include<iostream>
#include<string>

using namespace std;

int x[10 + 2], y[10 + 2], n;
string s;

bool ok(int v){
	int xx = x[v], yy = y[v];
	for (int i = 1; i < n; i++){
		xx += x[s[i] - '0'] - x[s[i - 1] - '0'];
		yy += y[s[i] - '0'] - y[s[i - 1] - '0'];

		bool fail = 1;
		for (int j = 0; fail && j < 10; j++)
			if (x[j] == xx && y[j] == yy)	fail = 0;
		if (fail)	return false;
	}
	return true;
}

int main(){
	cin >> n >> s;
	x[0] = 3, y[0] = 1;
	x[1] = 0, y[1] = 0;
	x[2] = 0, y[2] = 1;
	x[3] = 0, y[3] = 2;
	x[4] = 1, y[4] = 0;
	x[5] = 1, y[5] = 1;
	x[6] = 1, y[6] = 2;
	x[7] = 2, y[7] = 0;
	x[8] = 2, y[8] = 1;
	x[9] = 2, y[9] = 2;
	int cnt = 0;
	for (int i = 0; cnt < 2 && i < 10; i++)
		if (ok(i))	cnt++;
	if (cnt > 1)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}