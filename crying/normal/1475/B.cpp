#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+10;
int t,n,f[MAXN];
int main(){
	f[2020]=f[2021]=1;
	for(int i=2022;i<=1000000;i++){
		f[i]=f[i-2020] || f[i-2021];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(f[n]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}