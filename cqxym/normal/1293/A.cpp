#include<stdio.h>
#include<map>
#define R register int
using namespace std;
map<int,bool>Q;
int main(){
	int t,n,s,k,x,y;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d%d%d",&n,&s,&k);
		Q.clear();
		for(R j=0;j!=k;j++){
			scanf("%d",&x);
			Q[x]=true;
		}
		x=y=2e9;
		for(R j=s;j>=s-k&&j!=0;j--){
			if(Q[j]==false){
				x=s-j;
				break;
			}
		}
		for(R j=s+1;j<=s+k&&j<=n;j++){
			if(Q[j]==false){
				y=j-s;
				break;
			}
		}
		printf("%d\n",x<y?x:y);
	}
	return 0;
}