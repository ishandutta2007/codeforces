#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,i,j,a[10],b[10],s1,s2,x;
char ch;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>ch;
		a[ch-48]++;
		b[ch-48]++;
	}
	for (i=1;i<=n;i++)
	{
		cin>>ch;
		x=ch-48;
		while (x>-1&&!a[x]) x--;
		if (x>-1) {s1++;a[x]--;}
		x=ch-49;
		while (x>-1&&!b[x]) x--;
		if (x>-1) {s2++;b[x]--;}
	}
	cout<<n-s1<<endl<<s2;
	return 0;
}