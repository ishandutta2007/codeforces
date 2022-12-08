#include<bits/stdc++.h>
using namespace std;
int main(){
	long long  a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	long long num=0;
	if (a==b) num=-1; 
	printf("%lld",c*2+num+min(a,b)*2+1);
}