#include<iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], b[MAXN];
int main(){
	int n, m;	cin >> n >> m;
	int c, d;	cin >> c >> d;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < m; i++)	cin >> b[i];
	if (a[c - 1] < b[m - d])	cout << "YES\n";
	else cout << "NO\n";
	return	0;
}