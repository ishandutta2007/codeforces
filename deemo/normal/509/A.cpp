#include<iostream>
#include<algorithm>

using namespace std;

int n, c[20][20];

int main(){
	cin >> n;
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if (i == 0 || j == 0)
				c[i][j] = 1;
			else
				c[i][j] = c[i - 1][j] + c[i][j - 1];
			ans = max(ans, c[i][j]);
		}
	cout << ans << endl;
	return	0;
}