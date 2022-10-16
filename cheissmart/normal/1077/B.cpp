#include <bits/stdc++.h>

using namespace std;

int a[105];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<int> v;
	for(int i=0;i<n-2;i++) {
		if(a[i] && !a[i+1] && a[i+2])
			v.push_back(i);
	}
	v.push_back(222);
	int ans = 0, ct = 1;
	for(int i=1;i<v.size();i++) {
		if(v[i] == v[i-1]+2) {
			ct++;
		} else {
			ans += (ct+1)/2;
			ct = 1;
		}
	}
	cout << ans << endl;
}