#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>

#define MOD 1000000007

using namespace std;
typedef long long int lli;

lli powers[1000001];

void getPowers()
{
	lli twopower = 1;
	for(int i=0;i<1000001;++i)
	{
		powers[i] = twopower;
		twopower*=2;
		twopower%=MOD;
	}
}

lli getAmt(int acount, int bcount)
{
	lli sum = 0;
	sum = (powers[acount]+MOD-1)%MOD;
	sum *= bcount;
	sum %= MOD;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	getPowers();
	string s;
	cin >> s;
	int base = 0, current, acount, bcount;
	bool foundb = -1;
	int bstartpos = 0;
	lli sum = 0;
	for(int i=0;i<s.length();++i)
	{
		if(s.at(i) == 'b')
		{
			foundb = true;
			if(bstartpos == -1)
				bstartpos = i;
		}
		if(foundb && s.at(i) == 'a')
		{
			current = i;
			acount = bstartpos -base;
			bcount = current-bstartpos;
			sum += getAmt(acount, bcount);
			sum %= MOD;
			base = current-acount;
			foundb = false;
			bstartpos = -1;
		}
	}
	if(foundb == true)
	{
		current = s.length();
			acount = bstartpos -base;
			bcount = current-bstartpos;
			sum += getAmt(acount, bcount);
			sum %= MOD;
	}
	cout << sum << endl;

	return 0;
}