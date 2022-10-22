#include<iostream>
#include<algorithm>

using namespace std;

int col[200], row[200];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	char c[200][200];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> c[i][j];
			if (c[i][j] == '.')
				col[j] = i, row[i] = j;
		}		
	bool fl = 1;
	for (int i = 1; i <= n; i++)
		if (row[i] == 0)	fl = 0;
	if (fl){
		for (int i = 1; i <= n; i++)
			cout << i << " " << row[i] << endl;
		return 0;
	}
	fl = 1;
	for (int i = 1; i <= n; i++)
		if (col[i] == 0)	fl = 0;
	if (fl){
		for (int i = 1; i <= n; i++)
			cout << col[i] << " " << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
	return 0;
}