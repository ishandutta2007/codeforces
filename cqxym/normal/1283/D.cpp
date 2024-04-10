#include<stdio.h>
#include<map>
#include<queue>
using namespace std;
#define R register int
map<int,bool>Q;
struct Node{
	int dis,pos;
	friend bool operator<(Node x,Node y){
		return x.dis>y.dis;
	}
};
priority_queue<Node>S;
int ans[200000];
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);
	Node Tem;
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		Q[x]=true;
		Tem.dis=1;
		Tem.pos=x+1;
		S.push(Tem);
		Tem.pos=x-1;
		S.push(Tem);
	}
	long long t=0;
	for(R i=0;i!=m;i++){
		do{
			Tem=S.top();
			S.pop();
		}while(Q[Tem.pos]==true);
		ans[i]=Tem.pos;
		t+=Tem.dis;
		Q[Tem.pos]=true;
		Tem.dis++;
		Tem.pos++;
		S.push(Tem);
		Tem.pos-=2;
		S.push(Tem);
	}
	printf("%lld\n",t);
	for(R i=0;i!=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}