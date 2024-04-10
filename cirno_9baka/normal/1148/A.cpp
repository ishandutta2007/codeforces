#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	if(a==b)
		cout<<1ll*c*2+a+b;
	else
		cout<<1ll*c*2+1ll*min(a,b)*2+1;
}