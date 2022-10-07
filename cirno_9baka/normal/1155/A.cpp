#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i;
char c[500005];
int main(){
	scanf("%d\n",&n);
	scanf("%s",c);
	for(i=0;i+1<n;i++)
		if(c[i]>c[i+1])
		{
			printf("YES\n");
			printf("%d %d",i+1,i+2);
			return 0;
		}
	printf("NO");
}