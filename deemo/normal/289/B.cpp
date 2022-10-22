#include<iostream>
#include<vector>

using namespace std;

const int MAX = 100 + 4;

int a[MAX][MAX];

int main(){
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int ans = 1e9;
	for (int i = 1; i <= 1e4; i++){
		bool fl = 0;
		int sum = 0;
		for (int j = 0; !fl && j < n; j++)
			for (int k = 0; !fl && k < m; k++)
				if ((int)abs(a[j][k] - i) % d)	fl = 1;
				else	sum += (int)abs(a[j][k] - i) / d;
		if (fl)	continue;
		ans = min(ans, sum);
	}
	if (ans == 1e9)	ans = -1;
	cout << ans << endl;
	return 0;
}