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
	string s;
	for(int i=0;i<amt;++i)
	{
		if(i%4 == 0 || i%4 == 3)
			s += 'a';
		else if(i%4 == 1 || i%4 == 2)
			s += 'b';
	}
	cout << s << endl;

	return 0;
}