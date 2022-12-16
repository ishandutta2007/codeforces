// David Berard
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;

void print_line() {
	for(int i=0;i<n;++i) {
		cout << ".";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	if((k%2 == 0)) {
		cout << "YES" << endl;
		print_line();
		for(int nn=0;nn<2;++nn) {
			cout << ".";
			for(int i=0;i<n-2;++i) {
				if(i<(k/2)) cout << "#";
				else cout << ".";
			}
			cout << ".\n";
		}
		print_line();
	} else {
		cout << "YES" << endl;
		print_line();
		int top = min(k, n-2);
		int bot = k-top;
		cout << ".";
		for(int i=0;i<n-2;++i) {
			if(abs(i-(n-3)/2) <= top/2) cout << "#";
			else cout << ".";
		}
		cout << ".\n";
		cout << ".";
		for(int i=0;i<n-2;++i) {
			if(abs(i-(n-3)/2) <= bot/2 && abs(i-(n-3)/2) != 0) cout << "#";
			else cout << ".";
		}
		cout << ".\n";
		print_line();
	} 
	 
	
	return 0;
}