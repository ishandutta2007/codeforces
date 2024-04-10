#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

const int N = 3 * 100 * 100 + 7;
int a[N];

int main(){
	int n, t, sum = 1;
	cin >> n >> t;
	bool f = false;
	for (int i = 0; i < n - 1; i++)
		cin >> a[i];
	for (int i = 0; i < n - 1; i += a[i]){
		sum += a[i];
		f = (sum == t ? true : f);
	}
	cout << (f ? "YES" : "NO");
}