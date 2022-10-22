#include<iostream>
#include<string>

using namespace std;

char c[5][5];

int main(){
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> c[i][j];
	bool flag = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++){
			int c1 = 0, c2 = 0;
			for (int w = 0; w < 2; w++)
				for (int q = 0; q < 2; q++)
					if (c[i + w][j + q] == '#')	c1++;
					else	c2++;
			if (c1 >= 3 || c2 >= 3)	flag = 1;
		}
	if (flag)	cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}