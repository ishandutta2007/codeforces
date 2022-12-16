#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	int amt;
	cin >> amt;
	cout << ((amt-1)/2) << endl;

	return 0;
}