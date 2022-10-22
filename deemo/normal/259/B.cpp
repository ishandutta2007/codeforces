#include<iostream>

using namespace std;

int c[5][5], d[5][5];

int main(){
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> c[i][j];

	int ans;
	bool fl = true;
	for (ans = 1; fl; ans++){
		fl = false;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				d[i][j] = c[i][j];
		int sum = c[0][1] + c[0][2] + ans;
		d[0][0] = ans;
		d[1][1] = sum - d[1][0] - d[1][2];
		d[2][2] = sum - d[2][0] - d[2][1];

		if (d[0][0] + d[0][1] + d[0][2] != sum)	fl = 1;
		if (d[1][0] + d[1][1] + d[1][2] != sum)	fl = 1;
		if (d[2][0] + d[2][1] + d[2][2] != sum)	fl = 1;
	
		if (d[0][0] + d[1][0] + d[2][0] != sum)	fl = 1;
		if (d[0][1] + d[1][1] + d[2][1] != sum)	fl = 1;
		if (d[0][2] + d[1][2] + d[2][2] != sum)	fl = 1;

		if (d[0][0] + d[1][1] + d[2][2] != sum)	fl = 1;
		if (d[1][1] + d[2][0] + d[0][2] != sum)	fl = 1;
	}
	ans--;
	
	int sum = c[0][1] + c[0][2] + ans;
	c[0][0] = ans;
	c[1][1] = sum - c[1][0] - c[1][2];
	c[2][2] = sum - c[2][0] - c[2][1];

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			cout << c[i][j] << " ";
		cout << endl;
	}
	return 0;
}