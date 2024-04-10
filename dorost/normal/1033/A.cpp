#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	int a1, a2, b1, b2, c1, c2;
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	if (a1 == b1 || a2 == b2 || a1 == c1 || a2 == c2)
		return cout << "NO", 0;
	if ((b1 < a1 && c1 < a1 && b2 < a2 && c2 < a2) || (b1 < a1 && c1 < a1 && b2 > a2 && c2 > a2) || (b1 > a1 && c1 > a1 && b2 < a2 && c2 < a2) || (b1 > a1 && c1 > a1 && b2 > a2 && c2 > a2)){
		cout << "YES";
	}else
		cout << "NO";
}