#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 10;

int n, l, a[MAXN], b[MAXN], sec[MAXN], vec[MAXN];

int main(){
	cin >> n >> l;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> b[i];
	for (int i = 0; i + 1 < n; i++)
		vec[i] = (a[i+1] - a[i])
			, sec[i] = (b[i+1] - b[i]);

	vec[n - 1] = l-a[n - 1] + a[0];
	sec[n - 1] = l-b[n - 1] + b[0];

	for (int i = 0; i < n; i++){
		rotate(vec, vec + 1, vec+n);
		bool fail = 0;
		for (int j = 0; j < n; j++)
			if (vec[j] != sec[j])	fail = 1;
		if (!fail){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}