#include<bits/stdc++.h>
const int K=30;
int Gcd(int a,int b){return b?Gcd(b,a%b):a;}
int n,b[K],a,s;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int j=0;j<K;j++)b[j]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		for(int j=0;j<K;j++)b[j]+=a>>j&1;
	}
	s=0;
	for(int j=0;j<K;j++)s=Gcd(s,b[j]);
	for(int i=1;i<=n;i++)if(s%i==0)printf("%d ",i);puts("");
	}return 0;
}