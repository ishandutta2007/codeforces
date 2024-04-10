#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005;
int n,i;
long long ans=0;
char c[100005];
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	for(i=1;i<=n;i++)
		if((c[i]-'0')&1^1)
			ans+=i;
	cout<<ans;
}