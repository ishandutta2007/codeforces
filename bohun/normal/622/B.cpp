#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

int main()
{
	string s;
	cin >> s;
	int a = 10 * (s[0] - '0') + s[1] - '0';
	int b = 10 * (s[3] - '0') + s[4] - '0';
	int c;
	cin >> c;
	b += c;
	a += b / 60;
	a %= 24;
	b %= 60;
	if(a / 10 == 0)
		cout << 0;
	cout << a;
	cout << ":";
	if(b / 10 == 0)
		cout << 0;
	cout << b;
	
	
		
	return 0;
}