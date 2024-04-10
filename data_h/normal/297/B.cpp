#include<cstdio>
#include<cstring>
#include<algorithm>
#define MaxN 500010
using namespace std;
struct state{
	int event,det;
}Que[MaxN];
bool cmp(state a,state b){return a.event>b.event;}
int N,M,K,a1,flag,Qtail;
int main(){
	int i,j;
	scanf("%d%d%d",&N,&M,&K);
	for(i=1;i<=N;++i){
		scanf("%d",&a1);
		Que[++Qtail].event=a1;
		Que[Qtail].det=1;
	}
	for(i=1;i<=M;++i){
		scanf("%d",&a1);
		Que[++Qtail].event=a1;
		Que[Qtail].det=-1;
	}
	sort(Que+1,Que+Qtail+1,cmp);
	int pre=0;
	for(i=1;i<=Qtail;++i){
		pre+=Que[i].det;//printf("%d:%d\n",i,pre);
		if(Que[i].event==Que[i+1].event)
			continue;
		if(pre>0)
			flag=1;
	}
	if(flag)
		puts("YES");
	else
		puts("NO");
	return 0;
}