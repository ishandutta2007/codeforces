#include<iostream>
#include<algorithm>

using namespace std;

char c[6][6];
int cnt[20];

int main(){
	int k;	cin >> k;
	bool fl = 1;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			cin >> c[i][j];
			if (c[i][j] != '.'){
				cnt[c[i][j] - '0']++;
				if (cnt[c[i][j] - '0'] > 2 * k)	fl = 0;
			}
		}
	if (fl)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}