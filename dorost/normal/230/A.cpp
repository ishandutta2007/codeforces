#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int s, n;
	cin >> s >> n;
	pair <int, int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		if(s <= a[i].first){
			cout << "NO";
			return 0;
		}
		s += a[i].second;
	}
	cout << "YES";
}