#include<bits/stdc++.h>
#define LL long long
using namespace std;
int calc(int x,int y){
	int z=y,res=1;
	while(z<x)z+=y-1,res++;
	return res;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,k;set<int>s;
		s.clear(); 
		scanf("%d%d",&n,&k);
		for(int i=1,x;i<=n;i++)scanf("%d",&x),s.insert(x);
		if(k==1){
			if(s.size()>1)puts("-1");
			else puts("1");
		}else printf("%d\n",calc(s.size(),k));
	}
	return 0;
}