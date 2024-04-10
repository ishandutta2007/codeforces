#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
int main()
{
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		int a;
		cin >> a;
		bool ok = 0;
		for(ll j = 1; 100000 >= j; ++j)
		{
			if(j * j == a)
				continue;
			//if( j <= 10)
			//cout << sqrt((ld)(j * j) / (j * j - a)) << ""<< j <<endl;
			if((j * j) / (j * j - a) <= 0)
				continue;
			ll liczba = sqrt((ld)(j * j) / (j * j - a));	
			if( liczba <= 0)
				continue;
			if(a == j * j - (j / liczba) * (j / liczba))
			{
				cout << j << " " << liczba << endl;
				ok = 1;
				break;
			}
		}
		if(!ok)
		cout << -1 << endl;
	}
}