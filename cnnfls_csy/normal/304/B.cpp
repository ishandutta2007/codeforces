#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<cmath>
#include<string>
#include<vector>
#include<deque>
#include<set>
#include<bitset>
#include<map>
#include<functional>
#include<utility>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm> 
#include<set>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
int year[2039],month[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int as,bs,cs,ae,be,ce,cnt;
int main()
{
	for (int i=1900;i<2039;i++)
	{
		if (!(i%4) && i%100 || !(i%400)) year[i]=366;
		else year[i]=365;
	}
	scanf("%d:%d:%d",&as,&bs,&cs);
	scanf("%d:%d:%d",&ae,&be,&ce);
	if (as==ae && bs==be && cs==ce)
	{
		cout<<0;
		return 0;
	}
	if (as>ae || (as==ae && bs>be) || (as==ae && bs==be && cs>ce))
		swap(as,ae),swap(bs,be),swap(cs,ce);
	for (int i=as+1;i<ae;i++)
		cnt+=year[i];
	if (as!=ae)
	{
		for (int i=bs+1;i<=12;i++)
		{
			cnt+=month[i];
			if (i==2 && year[as]==366) cnt+=29;
			else if (i==2) cnt+=28; 
		}
		for (int i=1;i<be;i++)
		{
			cnt+=month[i];
			if (i==2 && year[ae]==366) cnt+=29;
			else if (i==2) cnt+=28; 
		}
	}
	else 
	{
		for (int i=bs+1;i<be;i++)
		{
			cnt+=month[i];
			if (i==2 && year[as]==366) cnt+=29;
			else if (i==2) cnt+=28; 
		}
	}
	if (bs!=be || as!=ae)
	{
		cnt+=month[bs]-cs;
		if (bs==2 && year[as]==366) cnt+=29;
		else if (bs==2) cnt+=28; 
		cnt+=ce;
	}
	else 
		cnt+=ce-cs;
	printf("%d",cnt);
}