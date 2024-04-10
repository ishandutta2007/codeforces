#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++){
		if (a[i] < 0){
			cout << "NO\n";
			return 0;
		}
		a[i] &= 1;
		if (a[i]){
			a[i + 1]--;
			if (i + 1 == n){
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}