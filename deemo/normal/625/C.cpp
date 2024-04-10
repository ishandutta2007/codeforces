#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 500 + 10;

int n, k;
int c[MAXN][MAXN], sum;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int cur = n * n;
	for (int i = n; i; i--)
		for (int j = n; j >= k; j--, cur--){
			if (j == k)	sum += cur;
			c[i][j] = cur;
		}
	for (int i = n; i; i--)
		for (int j = k - 1; j; j--, cur--)
			c[i][j] = cur;

	cout << sum << "\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << c[i][j] << " ";
		cout << "\n";
	}
	return	0;
}