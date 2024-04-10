#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;
typedef long double ld;

int a, b, c, d, aa = -1, bb;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (ld(a) / ld(b) < ld(c) / ld(d)){
		aa = b*c - a * d;
		bb = b * c;
	}
	else if (ld(a) / ld(b) > ld(c) / ld(d)){
		aa = a * d - b * c;
		bb = a * d;
	}

	if (aa != -1){
		int g = __gcd(aa, bb);
		aa /= g;
		bb /= g;
		cout << aa << "/" << bb << endl;
		return 0;
	}


	cout << 0 << "/" << 1 << endl;
	return 0;
}