#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500005;
int T,n,m,ans;
int a[maxn];
string s; 
int main(){
	scanf("%d%d",&n,&m); 
	if(n>30)
		printf("%d\n",m);
	else printf("%d\n",m%(1<<n));
	return 0;
}