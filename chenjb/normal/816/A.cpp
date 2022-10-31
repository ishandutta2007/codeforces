#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int x,y;
	scanf("%d:%d",&x,&y);
	int ans=0;
	while (1==1)
	{
		if (x/10==y%10&&y/10==x%10)break;
		y++;
		if(y>=60)y=0,x++;
		if(x>=24)x=0;
		ans++;

	}
	printf("%d\n",ans);
	return 0;
}