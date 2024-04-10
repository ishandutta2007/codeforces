#include<bits/stdc++.h>
using namespace std;
int x,k;
int main(){
	scanf("%d",&x);
	k=x%4;
	if(k==3)printf("2 A");
	if(k==2)printf("1 B");
	if(k==1)printf("0 A");
	if(!k)printf("1 A");
	return 0;
}