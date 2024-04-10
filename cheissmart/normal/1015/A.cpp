#include <bits/stdc++.h>

using namespace std;

bool a[300];

int main()
{
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		int l, r;
		cin >> l >> r;
		for(int j=l;j<=r;j++)
			a[j] = 1;
	}
	int ct = 0;
	for(int i=1;i<=m;i++)
		if(!a[i])
			ct++;
	cout << ct << endl;
	for(int i=1;i<=m;i++)
		if(!a[i])
			cout << i << " ";
	cout << endl;
}