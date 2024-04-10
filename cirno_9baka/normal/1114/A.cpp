#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
int x,y,z,a,b,c;
int main(){
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d %d %d",&a,&b,&c);
	if(a>=x&&a+b>=x+y&&a+b+c>=x+y+z)
		printf("YES");
	else
		printf("NO");
}