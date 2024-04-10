#include<stdio.h>
bool t[200000];
int Gcd(int a,int b){
	return b==0?a:Gcd(b,a%b);
}
int main(){
	int n,d,e;
	scanf("%d%d%d",&n,&d,&e);
	e*=5;
	if(n>d*e*2){
		printf("%d",n%Gcd(d,e));
		return 0;
	}
	t[0]=true;
	for(register int i=1;i<=n;i++){
		if(i>=d&&t[i-d]==true){
			t[i]=true;
		}else if(i>=e&&t[i-e]==true){
			t[i]=true;
		}
	}
	d=n;
	while(t[d]==false){
		d--;
	}
	printf("%d",n-d);
	return 0;
}