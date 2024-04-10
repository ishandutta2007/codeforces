#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, d, m, l;
	cin >> n >> d >> m >> l;
	ll cur = 0;
	while (cur % m <= l){
		if (cur/m >= n)	break;
		if (l-cur%m <= d)	cur += d;
		else	cur += (l-cur%m)/d * d;
	}
	cout <<cur << endl;
	return 0;
}