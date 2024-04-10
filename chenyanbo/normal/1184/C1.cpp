#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int n,a[1001][1001],t;
int main()
{
	n=read();
	for(int i=1;i<=n*4+1;++i)a[read()][read()]=1;
	/*
	for(int i=0;i<=50;++i)
	for(int j=0;j<=50;++j)b[i]+=a[i][j];
	for(int j=0;j<=50;++j)
	for(int i=0;i<=50;++i)c[j]+=a[i][j]; */
	
	for(int i=0;i<=50;++i)
	for(int j=0;j<=50;++j)
	for(int k=n-1;k<=50;++k){
		t=0;
		for(int o=j;o<=j+k;++o)t+=a[i][o]+a[i+k][o];
		for(int o=i+1;o<i+k;++o)t+=a[o][j]+a[o][j+k];
		if(t==n*4){
			for(int o=j;o<=j+k;++o)a[i][o]=0,a[i+k][o]=0;
			for(int o=i+1;o<i+k;++o)a[o][j]=0,a[o][j+k]=0;
			for(int i=0;i<=50;++i)
			for(int j=0;j<=50;++j)if(a[i][j])
			{
				//
				printf("%d %d \n",i,j);
				return 0;}
		}
	}
}