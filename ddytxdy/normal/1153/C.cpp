#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=3e5+50;
int n,num1,num2,now1,now2;char s[N];
int main(){
	scanf("%d",&n);
	if(n&1){
		puts(":(");return 0;
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='(')num1++;
		if(s[i]==')')num2++;
	}
	for(int i=1;i<=n;i++){
		if(now1<=now2&&i!=1){
			puts(":(");return 0;
		}
		if(s[i]=='(')num1--,now1++;
		if(s[i]==')')num2--,now2++;
		if(s[i]=='?'){
			if((num1+now1)<n/2)now1++,s[i]='(';
			else now2++,s[i]=')';
		}
	}
	if(now1==now2)printf("%s",s+1);
	else puts(":(");
	return 0;
}