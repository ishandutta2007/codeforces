#include <iostream>

using namespace std;

int g(int d) {
	if(d==0) return 6;
	if(d==1) return 2;
	if(d==2) return 5;
	if(d==3) return 5;
	if(d==4) return 4;
	if(d==5) return 5;
	if(d==6) return 6;
	if(d==7) return 3;
	if(d==8) return 7;
	if(d==9) return 6;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	int a,b,c=0;
	cin >> a >> b;
	for(int i = a; i <= b; ++i) {
		int m = i;
		while(m) {
			c += g(m%10);
			m/=10;
		}
	}
	cout << c << "\n";
	return 0;
}