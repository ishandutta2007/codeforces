#include<bits/stdc++.h>
using namespace std;
void Solve(){
	int a,b,c,d,e,ans=0;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	if(d>e){
		ans+=min(b,a/2)*d;
		a-=b*2;
		if(a>0){
			ans+=min(c,a/2)*e;
		}
	}else{
		ans+=min(c,a/2)*e;
		a-=c*2;
		if(a>0){
			ans+=min(b,a/2)*d;
		}
		
	}
	printf("%d\n",ans);
}
int main(){
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		Solve();
	}
	return 0;
}