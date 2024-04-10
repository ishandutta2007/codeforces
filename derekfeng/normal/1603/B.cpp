#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int sol(int a,int b){
	if(a<=b)return b-b%a/2;
	return a+b;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		printf("%d\n",sol(a,b));
	}
}