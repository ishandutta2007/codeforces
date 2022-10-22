#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int x[n], y[n];
		bool ans = true;
		pair <int, int> a[n];
		for (int i = 0; i < n; i++){
			cin >> x[i] >> y[i];
			a[i] = make_pair(x[i], y[i]);
		}
		sort(a, a+ n);
		for(int i = 1; i < n; i++){
			//cin >> x[i] >> y[i];
			if(a[i].F < a[i - 1].F || a[i].S < a[i - 1].S){
				ans = false;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
		if(ans){
			for(int i = 0; i < a[0].F; i++)
				cout << 'R';
			for (int i = 0; i < a[ 0].S; i++)
				cout << 'U';
			for (int i = 1; i < n; i++){
				int x1 = a[i].F - a[i - 1].F;
				int y1 = a[i].S - a[i - 1].S;
				for (int j = 0; j < x1; j++)
					cout << 'R';
				for (int j = 0; j < y1; j++)
					cout << 'U';
			}
			cout << endl;
		}
	}
}