#include<stdio.h>
#include<queue>
#include<map>
using namespace std; 
#define R register int
map<int,bool>b;
deque<int>Q;
int main(){
	int n,k,x,y;
	scanf("%d%d",&n,&k);
	for(R i=0;i<n;i++){
		scanf("%d",&x);
		if(b[x]==false){
			b[x]=true;
			if(Q.size()==k){
				y=Q.back();
				b[y]=false;
				Q.pop_back();
			}
			Q.push_front(x);
		}
	}
	x=Q.size();
	printf("%d\n",x);
	for(R i=0;i<x;i++){
		printf("%d ",Q.front());
		Q.pop_front();
	}
	return 0;
}