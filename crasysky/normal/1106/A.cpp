#include <iostream>
using namespace std;
char s[503][503];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> s[i];
	int ans = 0;
	for (int i = 2; i < n; ++ i)
		for (int j = 1; j < n - 1; ++ j)
			if (s[i][j] == 'X' && s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' && s[i + 1][j - 1] == 'X' && s[i + 1][j + 1] == 'X')
				++ ans;
	cout << ans << endl;
}