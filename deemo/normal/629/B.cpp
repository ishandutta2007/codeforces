#include<iostream>

using namespace std;

const int MAXN = 5e3 + 100;

int n, l[MAXN], r[MAXN];
char g[MAXN];

int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> g[i] >> l[i] >> r[i];
	int ans = 0;
	for (int i = 1; i <= 366; i++){
		int a = 0, b = 0;
		for (int j = 0; j < n; j++)
			if (l[j] <= i && i <= r[j]){
				if (g[j] == 'F')	a++;
				else	b++;
			}
		ans = max(ans, 2 * min(a, b));
	}
	cout << ans << "\n";
	return	0;
}