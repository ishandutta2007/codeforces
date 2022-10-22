#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500005;
int T,n,ans,k;
int a[maxn];
string s; 
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0,scanf("%d%d",&n,&k); 
		if(k>(n+1)/2){
			puts("-1");
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				if((i&1)&&i==j&&(i+1)/2<=k)
					putchar('R');
				else putchar('.');
			puts("");
		}
	}
	return 0;
}