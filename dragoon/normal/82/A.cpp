#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

char name[10][20]=
{
"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main()
{
	int n,sz,i;
	 
	scanf("%d",&n);
	sz = 1;
	while(1)
	{
		for(i=0;i<5;i++)
		{
			if(n<=sz)
			{
				printf("%s\n",name[i]);
				goto e;
			}

			n-=sz;
		}

		sz*=2;
	}
e:
	sz = 1;

	return 0;
}