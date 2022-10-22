#include<iostream>

using namespace std;

const int MAXN = 200;

int n, row[MAXN], col[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			char c;	cin >> c;
			if (c == 'C')
				row[i]++, col[j]++;
		}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += row[i] * (row[i] - 1) / 2, ans += col[i] * (col[i] - 1)/ 2;
	cout << ans << "\n";
	return	0;
}