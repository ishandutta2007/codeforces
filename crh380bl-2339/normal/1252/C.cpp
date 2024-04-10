#include<bits/stdc++.h>
using namespace std;
int gcd(int n,int m){
	return m==0?n:gcd(m,n%m);
}
int main(){
	int T;
	int n,m;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=100-n;
		int g=gcd(n,m);
		printf("%d\n",100/g);
	}
	return 0;
}