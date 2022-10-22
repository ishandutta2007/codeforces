#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int n, m;	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i * i + j == n && i + j * j == m)	ans++;
	cout << ans << endl;
	return 0;
}