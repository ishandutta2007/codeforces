#include<bits/stdc++.h>
using namespace std;
int n;
int S=1;
int bigger[105],smaller[105];
int p[105];
int main(){
	scanf("%d",&n);
	fflush(stdout);
	for(int i=1;i<n;i++){
		printf("? ");
		for(int j=1;j<n;j++)printf("%d ",i+1);
		printf("%d ",1);
		fflush(stdout);
		int x;scanf("%d",&x);
		if(x!=0)bigger[i]=x,S++;
		fflush(stdout);
	}
	for(int i=1;i<n;i++){
		printf("? ");
		for(int j=1;j<n;j++)printf("%d ",1);
		printf("%d ",i+1);
		fflush(stdout);
		int x;scanf("%d",&x);
		if(x!=0)smaller[i]=x;
		fflush(stdout);
	}
	p[n]=S;
	for(int i=1;i<=n;i++){
		if(bigger[i])p[bigger[i]]=S-i;
		if(smaller[i])p[smaller[i]]=S+i;
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	fflush(stdout);
}