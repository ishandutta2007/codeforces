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
int n,i,ans;
char c[500005];
int main(){
	scanf("%d",&n);
	scanf("%s",c);
	for(i=0;i<n-10;i++)
		if(c[i]=='8')
			ans++;
	if(ans>(n-11)/2)
		printf("YES");
	else
		printf("NO");
}