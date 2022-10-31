#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = 7005;

ll a[N];
int b[N];
int n;
int owns[N] = {};
ll sum = 0;
int num;

inline bool dom(int i, int j) {
	return ((a[j] & a[i]) != a[i]) && (a[i] != a[j]);
}

void remove(int i) {
	--num;
	sum -= b[i];
	for(int j = 0; j < n; ++j)
		owns[j] -= dom(j, i);
	owns[i] = 0;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	sum = 0;
	num = n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		sum += b[i];
	}
	for(int i = 0; i < n; ++i) 
		for(int j = 0; j < n; ++j)
			owns[i] += dom(i, j);

	while(true) {
		bool removed = false;
		for(int i = 0; num > 1 && i < n; ++i) {
			if(owns[i] == num-1) {
				removed = true;
				remove(i);
			}
		}
		if(removed == false)
			break;
	}
	if(num < 2) cout << "0\n";
	else cout << sum << '\n';
}