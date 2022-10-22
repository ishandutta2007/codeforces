#include<bits/stdc++.h>

using namespace std;

const int MAXN = 4e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);
	int mid = n/2;
	if (n % 2 == 0)	mid--;
	cout << a[mid] << endl;
	return 0;
}