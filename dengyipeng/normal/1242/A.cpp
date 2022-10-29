#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;

ll n;

int main(){
	scanf("%lld",&n);
	for(int i=2;i<=sqrt(n);i++) if (n%i==0){
		while (n%i==0) n/=i;
		if (n!=1) printf("1\n");
		else printf("%d",i);
		return 0;
	}
	printf("%lld",n);
}