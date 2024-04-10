#include<bits/stdc++.h>
using namespace std;
int Pow(int a,int b){
	int s=1;
	for(int i=0;i<b;i++){
		s*=a;
	}
	return s;
}
int main(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	printf("%d %d",Pow(2,l)-1-l+n,Pow(2,r)-1+Pow(2,r-1)*(n-r)); 
	return 0;
}