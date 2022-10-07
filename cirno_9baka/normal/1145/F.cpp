#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,a[]={0,1,1,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0},i,ans;
char c[1005];
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;i++)
		ans+=a[c[i]-'A'];
	if(ans==n||ans==0)
		printf("YES");
	else
		printf("NO");
}