#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, in[3];
	cin >> in[0] >> in[1] >> in[2];
	sort(in, in+3);
	a = in[0], b = in[1], c = in[2];
	if(a + b > c)
		cout << 0 << endl;
	else 
		cout << c - a - b + 1 << endl;
}