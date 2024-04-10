#include<bits/stdc++.h>

using namespace std;

int y[4][4];

int main(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)	cin >> y[i][j];
	for (int i = 0; i < 4; i++)
		if (y[i][3]){
			int x = 0;
			for (int j = 0; j < 3; j++) x |= y[i][j];
			x |= y[(i+1)%4][0];
			x |= y[(i+2)%4][1];
			x |= y[(i+3)%4][2];
			if (x){
				cout << "YES\n";
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}