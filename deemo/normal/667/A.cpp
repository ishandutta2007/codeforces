#include<iostream>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<utility>
#include<iomanip>
#include<climits>

using namespace std;

typedef long long ll;
typedef long double ld;

ld d, h, v, e;

int main(){
	cout << fixed << setprecision(12);
	cin >> d >> h >>v >> e;
	ld s = d/2. * d/2. * acos(-1);
	v = v/s;
	if (v <= e){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	v -= e;
	cout << h/v << "\n";
	return 0;
}