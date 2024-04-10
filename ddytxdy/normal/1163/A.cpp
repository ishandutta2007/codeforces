#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(m==0)printf("%d",1);
	else if(m<=n/2)printf("%d",m);
	else printf("%d",n-m);
}