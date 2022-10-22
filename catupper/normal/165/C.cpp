/*card[2][5001],a,b,i,j,n,t;
main(){
	scanf("%d%*d",&a);
	for(;i-a;scanf("%d",card[0]+i++));
	for(;~scanf("%d",card[1]+j++););
	for(;--j;n=n>t?n:t){
		for(i=t=0;i<a;)card[0][i++]-card[1][j+t]?:t++;
	}
	n!=printf("%d\n",n);
} */
#include<stdio.h>
#include<iostream>
using namespace std;
int num[1000001],a,i,t,ps;
long long int res=0;
int main(){
	scanf("%d",&a);
	for(t=1;~scanf("%1d",&i);t++){
		if(i==1){
			num[++ps]=t;
		}
		if(a==0){
			res+=t-num[ps];
		}
		else if(ps>=a){
			res+=num[ps-a+1]-num[ps-a];
			
		}		
	}	
	cout << res << endl;
	
}


// 1111
// 1234