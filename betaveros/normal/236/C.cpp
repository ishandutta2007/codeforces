#include <iostream>
using namespace std;
typedef long long int lli;

lli gcd(lli a, lli b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

bool cop(lli x, lli y) { return gcd(x, y) == 1; }

bool allCoprime(lli x, lli y, lli z){
	return gcd(x,y) == 1 && gcd(y,z) == 1 && gcd(z,x) == 1;
}

int main(){
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl; return 0;
	}
	if (n == 2) {
		cout << 2 << endl; return 0;
	}
	lli t1 = n;
	lli t2 = n - 1;
	lli t3 = n - 2;
	lli best = 0;
	lli zero = 0;
	while (true){
		if (allCoprime(t1,t2,t3)){
			lli res = t1*t2*t3;
			if (best < res) {
				best = res;
				//cout << best << endl;
			}
		}
		t3--;
		if (t3 <= 0){
			t2--;
			while (t2 > 0 && !cop(t2,t1)) t2--;
			if (t2 <= 0 || (t1*t2*(t2-1)) < best){
				t1--;
				//cout << "t1:" << t1 << endl;
				if (t1 <= 0 || (t1*(t1-1)*(t1-2)) < best) break;
				t2 = t1 - 1;
			}
			t3 = t2 - 1;
		}
	}
	cout << best << endl;
}