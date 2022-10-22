#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char c[200][200];

int main(){
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			c[i][j] = '*';

	int z = 1, s = n/2, j = 0;
	while (z <= n){
		for (int i = s; i < s + z; i++)
			c[j][i] = 'D';
		s--;
		z += 2;
		j++;
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			if (i <= n/2)
				cout << c[i][j];
			else
				cout << c[n - i - 1][j];
		cout << endl;
	}
	return	0;	
}