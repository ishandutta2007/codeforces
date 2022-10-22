#include<bits/stdc++.h>
using namespace std;
int T,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		if(x>y)printf("%d\n",x+y);
		else printf("%d\n",y-((y%x)>>1));
	}
	return 0;
}