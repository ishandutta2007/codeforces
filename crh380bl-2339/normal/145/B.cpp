#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a1,a2,a3,a4,i;cin>>a1>>a2>>a3>>a4;
	if (a3-a4>1 || a4-a3>1) {puts("-1");return 0;}
	if (a3>a4)
	{
		if (a1<a3 || a2<a3) {puts("-1");return 0;}
		for (i=1;i<=a1-a3;i++) printf("4");
		for (i=1;i<=a3;i++) printf("47");
		for (i=1;i<=a2-a3;i++) printf("7");
	}
	else if (a3<a4)
	{
		if (a1<a4 || a2<a4) {puts("-1");return 0;}
		if (a4==1)
		{
			for (i=1;i<=a2;i++) printf("7");
			for (i=1;i<=a1;i++) printf("4");
		}
		else
		{
			printf("74");
			for (i=1;i<=a1-a4;i++) printf("4");
			for (i=1;i<=a4-2;i++) printf("74");
			for (i=1;i<=a2-a4;i++) printf("7");
			printf("74");
		}
	}
	else
	{
		if (a1<a3+1 && a2<a3+1) {puts("-1");return 0;}
		if (a1<a3 || a2<a3) {puts("-1");return 0;}
		if (a1>=a3+1)
		{
			for (i=1;i<=a1-a3-1;i++) printf("4");
			for (i=1;i<=a3;i++) printf("47");
			for (i=1;i<=a2-a3;i++) printf("7");
			printf("4");
		}
		else
		{
			printf("7");
			for (i=1;i<=a1-a3;i++) printf("4");
			for (i=1;i<=a3;i++) printf("47");
			for (i=1;i<=a2-a3-1;i++) printf("7");
		}
	}
}