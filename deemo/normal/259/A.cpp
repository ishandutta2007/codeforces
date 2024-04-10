#include<iostream>
#include<algorithm>

using namespace std;

char c[10][10];

int main(){
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			cin >> c[i][j];

	for (int i = 0; i < 8; i++){
		bool fl = 0;
		for (int k = 0; !fl && k < 8; k++){
			fl = 1;
			for (int j = 1; j < 8; j++)
				if (c[i][j] == c[i][j - 1])
					fl = 0;
			rotate(c[i], c[i] + 1, c[i] + 8);
		}
		if (!fl){
			cout << "NO\n";
			return	0;
		}
	}
	cout << "YES\n";
	return 0;
}