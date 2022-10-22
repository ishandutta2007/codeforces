#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char a[5][5], b[5][5];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			cin >> a[i][j];
	string aa = "";
	if (a[1][1] < 'D')	aa += a[1][1];
	if (a[1][2] < 'D')	aa += a[1][2];
	if (a[2][2] < 'D')	aa += a[2][2];
	if (a[2][1] < 'D')	aa += a[2][1];

	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 2; j++)
			cin >> b[i][j];
	string bb = "";
	if (b[1][1] < 'D')	bb += b[1][1];
	if (b[1][2] < 'D')	bb += b[1][2];
	if (b[2][2] < 'D')	bb += b[2][2];
	if (b[2][1] < 'D')	bb += b[2][1];
	

	for (int i = 0; i < 100; i++){
		if (aa == bb){
			cout << "YES\n";
			return	0;
		}
		rotate(aa.begin(), aa.begin() + 1, aa.end());
	}
	cout << "NO\n";
	return	0;
}