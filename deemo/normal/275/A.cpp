#include<iostream>
#include<cmath>

using namespace std;

int a[6][6];

int main(){
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 3; j++){
			int c = a[i - 1][j] + a[i + 1][j] + a[i][j] + a[i][j + 1] + a[i][j - 1];
			if (c % 2 == 0)	cout << 1;
			else	cout << 0;
		}	
		cout << endl;
	}
	return 0;
}