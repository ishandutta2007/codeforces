#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	int a, b, c, d;	cin >> a >> b >> c >> d;
	int ta = a + b;
	int tb = min(c, d);
	tb += max(c - tb, d - tb);
	if (ta <= tb)
		cout << "Polycarp\n";
	else{
		for (int i = 0; min(c, d); i++){
			int z = abs(a - (c - 1)) + abs(b - (d - 1));
			if (z <= i + 1){
				cout << "Polycarp\n";
				return 0;
			}
			c--, d--;
		}
		cout << "Vasiliy\n";
	}
	return 0;	
}