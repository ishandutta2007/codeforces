#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int n, a[N];

void win(int player) {
	if(player == 0)
		cout << "sjfnb\n";
	else cout << "cslnb\n";
	exit(0);
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a+n);
	int same = -1;
	for(int i = 1; i < n; ++i) {
		if(a[i] ==  a[i-1]) {
			if(same == -1)
				same = i-1;
			else {
				win(1);
			}
		}
	}
	if(same != -1) {
		if(a[same] == 0)
			win(1);
		--a[same];
		if(same > 0 && a[same] == a[same-1]) {
			win(1);
		}
	}
	ll moves = 0;
	for(int i = 0; i < n; ++i)
		moves += a[i] - i;
	win((moves%2) ^ (same == -1));
}