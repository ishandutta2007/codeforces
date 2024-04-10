/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
int c[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int32_t main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	bool h = false;
	for (int i = 0; i < 12; i++){
		int num29 = 0;
		bool f = true;
		for (int j = i; j < i + n; j++){
			if (a[j - i] == 29)
				num29++;
			if (c[j % 12] != a[j - i] && b[j % 12] != a[j - i])
				f = false;
			if (num29 > 1)
				f = false;
		}
		if (f)
			h = true;
	}
	cout << (h ? "Yes" : "NO");
}