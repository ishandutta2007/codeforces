#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

int n,n11,n10,n01,n00,n1,n2;
string s,t;

void hod(int& n, int& n11, int& n10, int& n01, int& n00)
{
	if (n11 || n10)
	{
		n++;
		if (n11)
			n11--;
		else
			n10--;
	}else
	{
		if (n01)
			n01--;
		else
			n00--;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n >> s >> t;
	for (int i=0; i<2*n; i++)
		if (s[i]=='1' && t[i]=='1')
			n11++;
		else
		if (s[i]=='1' && t[i]=='0')
			n10++;
		else
		if (s[i]=='0' && t[i]=='1')
			n01++;
		else
			n00++;

	while (n11 || n10 || n01 || n00)
	{
		hod(n1, n11, n10, n01, n00);
		hod(n2, n11, n01, n10, n00);
	}

	if (n1 > n2)
		cout << "First";
	else
	if (n2 > n1)
		cout << "Second";
	else
		cout << "Draw";
	cout << endl;
	return 0;
}