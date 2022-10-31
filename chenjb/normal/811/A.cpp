#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#define LL long long 

using namespace std;

int main()
{	
	int a,b;
	cin>>a>>b;
	for(int i=1;;i++)
	{
		if (i%2==1)
		{
			if (a<i){ cout<<"Vladik"<<endl; break; }
			a-=i;
		}
		else
		{
			if (b<i){ cout<<"Valera"<<endl; break; }
			b-=i;
		}
	}
	return 0;
}