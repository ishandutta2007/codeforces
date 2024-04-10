#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int T,a,b;
int gcd(int x,int y){return (x%y==0)?y:gcd(y,x%y);}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&a,&b);
		if (gcd(a,b)==1)
			printf("Finite\n");
		else 	
			printf("Infinite\n");
	}
}