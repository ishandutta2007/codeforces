#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#define LL long long
using namespace std;
int main()
{
	int k;
	cin>>k;
	for(int i=1;i<=26;i++)
	{
		putchar('a'+i-1);
		int now=1;
		if (k==0)break;
		while (k>=now)
		{
			k-=now;
			putchar('a'+i-1);
			now++;
		}
	}
	printf("\n");
}