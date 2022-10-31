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
	int n;
	cin>>n;
	for(int i=1;i<=n/4;i++)printf("aabb");
	if (n%4==1)printf("a");
	if (n%4==2)printf("aa");
	if (n%4==3)printf("aab");
	printf("\n");
	return 0;
}