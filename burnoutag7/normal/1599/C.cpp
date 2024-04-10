#include <bits/stdc++.h>
using namespace std;
typedef double db;
db P;
int n;
int main(){
	scanf("%d%lf",&n,&P);
	for(int i=0;i<=n;i++){
		db ret=0;
		int f0=i,f1=n-i;
		int t1=f0*(f0-1)*(f0-2)/6,t2=f0*(f0-1)/2*f1,t3=f0*f1*(f1-1)/2,t4=f1*(f1-1)*(f1-2)/6;
		int all=n*(n-1)*(n-2)/6;
		ret=((db)(t1+t2)+(db)t3*0.5)/(db)all;
		if(ret>=P){
			printf("%d",i);
			return 0;
		}
	}
}