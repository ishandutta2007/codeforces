#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a, b;
	cin >> a >> b;
	int h = 10 * (a[0] -'0') + a[1] -'0' + 10 * (b[0] - '0') + b[1] - '0';
	int m = 10 * (a[3] -'0')+ a[4] -'0'  + 10 * (b[3] - '0') + b[4] - '0';
	if(h % 2 == 1)
		m += 60;
	h /= 2;
	m /= 2;
	if(m >= 60)
	    h += 1, m -= 60;
	if(h / 10 == 0)
		cout << "0";
	cout << h << ":" ;
	if(m / 10 == 0)
		cout << "0";
	cout << m;
	
	return 0;
}