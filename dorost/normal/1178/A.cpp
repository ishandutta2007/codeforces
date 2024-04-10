/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 110;
pair <int, int> a[N];

int32_t main(){
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].S = i;
		sum += a[i].F;
	}
	sort (a + 1, a + n);
	int x = a[0].F;
	vector <int> v = {1};
	for (int i = 1; i < n; i++){
		if (a[i].F <= a[0].F / 2){
			x += a[i].F;
			v.push_back(a[i].S + 1);
		}
	}
	if (x > sum / 2){
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' '; 
	}else{
		cout << 0;
	}
}