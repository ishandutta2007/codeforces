#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,a[22],p,r[22];
int mo(int x){return x>=k?x-k:x;}
int main(){
	int t;cin>>t;while(t--){
		cin>>n>>k; p=0;
		for(int i=0;i<20;++i)a[i]=r[i]=0;
		while(!p){
			int ans=0; for(int i=20;~i;--i)ans=ans*k+mo(r[i]+a[i]),r[i]=mo(r[i]+mo(r[i]+a[i]));
			printf("%d\n",ans); fflush(stdout);
			a[0]++; for(int i=0;i<20;++i)if(a[i]==k)a[i]=0,a[i+1]++; else break;
			scanf("%d",&p);
		}
	}
}