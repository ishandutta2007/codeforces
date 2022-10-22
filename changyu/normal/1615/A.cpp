#include<bits/stdc++.h>
int n,a,s; 
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	s=0;
	for(int i=1;i<=n;i++)scanf("%d",&a),s+=a;
	puts(s%n==0?"0":"1");
	}return 0;
}