#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long sm = 0;
	for (int i = 0; i < n; i++)	cin >> a[i], sm += a[i];	
	sort(a, a+n);
	sm -= a[n - 1];
	cout << a[n - 1] - sm + 1 << "\n";
	return 0;
}