#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll a, b;

ll get(ll a, ll b){
	if (a == 0 || b == 0)	return	0;
	if (a == b && a == 1)	return	1;
	if (a > b)	swap(a, b);
	return	b/a + get(a, b % a);
}

int main(){
	cin >> a >> b;
	cout << get(a, b) << endl;
	return 0;
}