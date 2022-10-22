#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int c,d; scanf("%d%d",&c,&d);
		if(c>d) swap(c,d);
		if((d-c)&1) puts("-1");
		else{
			int ans=2;
			if((d+c)/2==0) --ans;
			if((d-c)/2==0) --ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}