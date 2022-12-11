#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r,x,minn=1e9,maxn;
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		minn=min(minn,x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		maxn=max(maxn,x);
	}
	if(minn>maxn)printf("%d",r);
	else printf("%d",r%minn+r/minn*maxn);
	return 0;
}