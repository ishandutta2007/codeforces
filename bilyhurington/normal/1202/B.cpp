#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,num[11],nd[11];
char s[2000010];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<n;i++) num[(s[i+1]-s[i]+10)%10]++;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				nd[k]=101;
			}
			for(int k=0;k<10;k++){
				for(int r=0;r<10;r++){
					if(!k&&!r) continue;
					nd[(k*i+r*j)%10]=min(nd[(k*i+r*j)%10],k+r);
				}
			}
//			for(int i=0;i<=9;i++) printf("%d ",nd[i]);
//			printf("\n");
			int ans=0;
			bool pd=0;
			for(int k=0;k<10;k++){
				if(!num[k]) continue;
				ans+=num[k]*nd[k];
				if(nd[k]==101) pd=1;
			}
			if(pd) printf("-1 ");
			else printf("%d ",ans-n+1);
		}
		printf("\n");
	}
}