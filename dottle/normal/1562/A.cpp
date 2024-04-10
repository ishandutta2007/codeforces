#include<bits/stdc++.h>
using namespace std;

int a,b,t; 

int main(){
	scanf("%d",&t);
	while(t--)
		scanf("%d%d",&a,&b),printf("%d\n",b%max(b/2+1,a));
}