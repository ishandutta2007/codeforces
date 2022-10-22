#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;

int n;
char c[MAXN][MAXN];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];

	bool fl = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			int cn = 0;
			for (int a = -1; a < 2; a++)
				for (int b = -1; b < 2; b++)
					if (abs(a) + abs(b) == 1)
						if (c[i + a][j + b] == 'o')	cn++;
			if (cn % 2 == 1)	fl = 1;
		}
	if (fl)
		cout << "NO\n";
	else
		cout << "YES\n";
	return	0;
}