#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


int gcd(int a, int b) {
	if(b) return gcd(b, a%b);
	return a;
}

int main() {
	int n, k;
	cin >> n >> k;
	int g = k;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		g = gcd(a, g);
	}
	cout << k/g << "\n";
	for(int i = 0; i < k; i += g) {
		cout << i << " ";
	}
	cout << "\n";
}