#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,ans;
char c[10005];
int main(){
	scanf("%s",c);
	n=strlen(c);
	for(i=0;i<n;i++)
		if(c[i]=='a')
			ans++;
	cout<<min(ans*2-1,n);
}