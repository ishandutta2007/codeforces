#include<stdio.h>
#include<map>
#include<set>
using namespace std;
#define R register int
#define P pair<int,int>
map<int,bool>C,T;
set<int>Q;
map<int,int>E;
int main(){
	int n,q,x,y,tem;
	scanf("%d%d",&n,&q);
	T[0]=false;
	T[n+1]=true;
	Q.insert(0);
	Q.insert(n+1);
	E[n+1]=E[0]=0;
	char c;
	set<int>::iterator t;
	for(R i=0;i!=q;i++){
		scanf("%d%d ",&x,&y);
		c=getchar();
		if(C[x]==false){
			C[x]=true;
			t=Q.upper_bound(x);
			if(c=='U'){
				tem=*t;
				if(T[tem]==false){
					E[x]=E[tem];
				}else{
					E[x]=n+1-tem;
				}
				printf("%d\n",y-E[x]);
				T[x]=false;
			}else{
				t--;
				tem=*t;
				if(T[tem]==false){
					E[x]=tem;
				}else{
					E[x]=E[tem];
				}
				printf("%d\n",x-E[x]);
				T[x]=true;
			}
			Q.insert(x);
		}else{
			puts("0");
		}
	}
	return 0;
}