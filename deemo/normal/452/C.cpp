#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;

int main(){
	cout << fixed << setprecision(12);
	cin >> n >> m;
	ld p = ld(1)/ ld(n);
	if (n * m - 1 != 0) p += (ld(n - 1)/n) * (ld(m - 1)/ ld(n * m - 1));
	cout << p << endl;
	return	0;	
}