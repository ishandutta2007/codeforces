#include <iostream>
using namespace std;
typedef long long LL;

int main(){
	LL N,m;
	LL res=0;
	cin >> N >> m;
	for(int i=0;i<N;i++){
		LL t,T,x,cost;
		cin >> t >> T >> x >> cost;
		LL n=T-t;
		if(n<=0){
			res+=m*x+cost;
			continue;
		}
		LL r=m/n;
		if(m%n!=0)r++;
		LL minimo=r*cost;
		if(x*m+cost<minimo)minimo=x*m+cost;
		if((r-1)*(cost-x*n)+x*m+cost<minimo)minimo=(r-1)*(cost-x*n)+x*m+cost;
		res+=minimo;
	}
	cout << res;
}

//~ 10 1
//~ 
//~ 8 6 3 4
//~ 
//~ 9 10 7 7
//~ 
//~ 1 3 9 5
//~ 
//~ 10 9 4 2
//~ 
//~ 1 10 2 10
//~ 
//~ 1 1 8 5
//~ 
//~ 5 5 9 2
//~ 
//~ 5 8 4 3
//~ 
//~ 4 4 9 7
//~ 
//~ 5 7 5 10