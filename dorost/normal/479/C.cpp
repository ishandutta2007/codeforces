/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
pair <int, int> a[N];
int b[N];

int32_t main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].F >> a[i].S;
	sort (a, a + n);
	int x = 0;
	for (int i = 0; i < n; i++){
		if (a[i].S >= x){
			b[i] = a[i].S;
		}else{
			b[i] = a[i].F;
		}
		x = b[i];
	}
//	for (int i = 0; i < n; i++)
//		cout << b[i] << ' ';
	cout << *max_element (b, b + n);
}