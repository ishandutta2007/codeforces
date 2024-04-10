/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 112345;
int a[N], b[N], c[N];

int32_t main(){
	int n;
	cin >> n;
	map <int, int> mp1, mp2, mp3;
	for (int i = 0; i < n; i++)
		cin >> a[i], mp1[a[i]] ++;
	for (int i = 0; i < n - 1; i++)
		cin >> b[i], mp2[b[i]] ++;
	for (int i = 0; i < n - 2; i++)
		cin >> c[i], mp3[c[i]] ++;
	for (int i = 0; i < n; i++){
		if (mp1[a[i]] != mp2[a[i]]){
			cout << a[i] << endl;
			break;
		}
	}
	for (int i = 0; i < n - 1; i++){
		if (mp2[b[i]] != mp3[b[i]]){
			cout << b[i] << endl;
			break;
		}
	}
}