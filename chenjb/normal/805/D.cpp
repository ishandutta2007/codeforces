#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 
#define inf 1000000007
using namespace std;
int main()
{
	LL pow[1001000];
	pow[0]=1;
	for(int i=1;i<=1000010;i++)pow[i]=(pow[i-1]*2)%inf;
	LL ans=0;
	int suma=0;
	char c=getchar();
	while (c=='a'||c=='b')
	{
		if (c=='b')ans=(ans+pow[suma]-1)%inf;
		if (c=='a')suma++;
		c=getchar();
	}
	cout<<ans<<endl;
	return 0;
}