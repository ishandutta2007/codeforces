#include<bits/stdc++.h>
#define read(N) scanf("%d",&N)
using namespace std;
int a[100003];
int main()
{
	int n;
	bool f=1;
	read(n);
	for(int i=1; i<=n; i++) read(a[i]);
	for(int i=1; i<=n; i++) if(a[i]%2 && f) f=!f,a[i]--,a[i]/=2;
	else if(a[i]%2) f=!f,a[i]++,a[i]/=2;
	else a[i]/=2;
	for(int i=1; i<=n; i++) printf("%d\n",a[i]);
	return 0;
}