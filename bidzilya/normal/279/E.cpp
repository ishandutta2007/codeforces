#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 2222222;

char c[N];

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> c;
	int n=strlen(c);
	int ans=0,i=n-1;
	while (i>=0)
	{
		int cnt=0;
		while (i>=0 && c[i]=='1'){cnt++;i--;}
		if (cnt==1)
			ans++;
		else
		if (cnt>1)
		{
			ans++;
			if (i<0){ans++;break;}
			c[i]='1';
			i++;
		}
		i--;
	}
	cout << ans << endl;
	return 0;
}