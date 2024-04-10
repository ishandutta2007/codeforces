#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		long long a,b;
		cin>>a>>b;
		if (a-b!=1){ puts("NO"); continue; }
		long long s=a+b;
		int flag=1;
		for(long long i=2;i<=sqrt(s);i++)
			if (s%i==0)flag=0;
		if (flag)puts("YES"); else puts("NO");
	}
}