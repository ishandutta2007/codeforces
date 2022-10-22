#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, b, c, s = 0;
		cin >> a >> b >> c;
		int a1[3] = {a, b, c};
		sort (a1, a1 + 3);
		a = a1[0];
		b = a1[1];
		c = a1[2];
//		cerr << a <<  ' ' << b << ' ' << c << endl;
		if (a){
			a--;
			s++;
		}
		if (b){
			b --;
			s ++;
		}
		if (c){
			c--;
			s++;
		}
		if (c && b){
			s++;
			c --;
			b --;
		}
		if (a && c){
			s ++;
			a --;
			c --;
		}
		if (b && a){
			a --;
			b --;
			s++;
		}
		if (a && b && c){
			s++;
		}
		cout << s << endl;
	}
}