#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e6;
int h,t,q[MAX_N];
int a[MAX_N],b[MAX_N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) scanf("%d",&b[i]);
	int k=1,cnt=1;
	for(;k<=n;++k)
		if(b[k]==1) break;
	if(k<=n){
		for(++k;k<=n;++k)
			if(b[k]==cnt+1) ++cnt;
			else break;
		if(k>n){
			int mi=0;
			for(int i=1;i<=n;++i)
				if(b[i]==1) break;
				else if(b[i]!=0)
					mi=min(mi,b[i]-cnt-i-1);
			if(mi>=0){
				printf("%d\n",n-cnt);
				return 0;
			}
		}
	}
		int mi=0;
		for(int i=1;i<=n;++i)
			if(b[i]!=0)
				mi=min(mi,b[i]-i-1);
		printf("%d\n",(-mi)+n);
		return 0;
}