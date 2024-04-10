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
int n,i,m;
int main(){
	scanf("%d %d",&n,&m);
	int k=(n-m)/2;
	for(i=1;i<=n;i++)
		if(i%(k+1)==0)
			printf("0");
		else
			printf("1");
}