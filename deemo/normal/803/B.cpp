#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, a[MAXN], b[MAXN];

int main(){
	memset(b, 63, sizeof(b));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	int lst = -1e9;
	for (int i = 0; i < n; i++){
		if (!a[i]) lst = i;
		b[i] = min(b[i], i-lst);
	}
	lst = 1e9;
	for (int i = n-1; ~i; i--){
		if (!a[i]) lst = i;
		b[i] = min(b[i], lst-i);
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
	return 0;
}