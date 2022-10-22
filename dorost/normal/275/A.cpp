#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int a[5][5] = {};
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			cin >> a[i][j];
	for(int i = 1; i < 4; i++){
		for (int j = 1; j < 4; j++){
			int ans = 1 + a[i][j + 1] + a[i][j - 1] + a[i + 1][j] + a[i - 1][j] + a[i][j];
			cout << ans % 2;	
		}
		cout << endl;
	}
}