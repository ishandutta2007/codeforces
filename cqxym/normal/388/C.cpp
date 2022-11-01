#include<stdio.h>
#include<queue>
using namespace std;
#define R register int
int main(){
	int n,m,x,ans1=0,ans2=0;
	scanf("%d",&n);
	priority_queue<int>Q;
	for(R i=0;i!=n;i++){
		scanf("%d",&m);
		for(R j=0;j!=m>>1;j++){
			scanf("%d",&x);
			ans1+=x;
		}
		if((m&1)==1){
			scanf("%d",&x);
			Q.push(x);
		}
		for(R j=0;j!=m>>1;j++){
			scanf("%d",&x);
			ans2+=x;
		}
	}
	while(Q.size()>1){
		ans1+=Q.top();
		Q.pop();
		ans2+=Q.top();
		Q.pop();
	}
	if(Q.empty()==false){
		ans1+=Q.top();
	}
	printf("%d %d",ans1,ans2);
	return 0;
}