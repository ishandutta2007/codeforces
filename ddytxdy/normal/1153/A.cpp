#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,t,x,y,ans,anss=1e9,w;
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x>=t)w=x-t;
		else{
			w=(t-x)%y;
			if(w!=0)w=y-w;
		}
		if(w<anss)ans=i,anss=w;
	}
	printf("%d",ans);
	return 0;
}