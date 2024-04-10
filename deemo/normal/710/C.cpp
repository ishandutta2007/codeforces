#include<bits/stdc++.h>

using namespace std;

const int MAXN = 49 + 5;

int n, a[MAXN][MAXN];
int sec[MAXN * MAXN], vec[MAXN * MAXN], sz, tt;

int main(){
	cin >> n;
	for (int i = 1; i <= n * n; i++)
		if (i & 1)	sec[sz++] = i;
		else	vec[tt++] = i;

	for (int i = 0; i < n; i++){
		bool turn = i & 1;
		for (int j = 0; j < n; j++){
			
			turn = !turn;
		}
	}

	for (int j = 0; j < n; j++)
		a[n/2][j] = 1;
	for (int i = 0; i < n; i++)
		a[i][n/2] = 1;
	
	int rem = n * n/ 2 +1;
	rem -= 2 * n - 1;
	while (rem){
		bool found = 0;
		for (int i = 0; !found && i < n/2; i++)
			for (int j = 0; !found && j < n/2; j++)
				if (!a[i][j]){
					a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = 
						a[n - i - 1][n - j - 1] = 1;
					found = 1;
					break;
				}
		rem -= 4;
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j])
				a[i][j] = sec[--sz];
			else
				a[i][j] = vec[--tt];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}