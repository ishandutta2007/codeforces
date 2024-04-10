#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	int n;
	cin >> n;
	pair <int, int> a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++){
		int x = a[i].second;
		if (x == 0){
			cout << a[1].first - a[0].first << ' ' << a[n - 1].first - a[0].first << endl;
		}else if(x == n - 1){
			cout << a[n - 1].first - a[n - 2].first << ' ' << a[x].first - a[0].first << endl;
		}else{
			cout << min(a[x].first - a[x - 1].first, a[x + 1].first - a[x].first) << ' ' << max(a[x].first - a[0].first, a[n - 1].first - a[x].first) << endl;
		}
	}
}