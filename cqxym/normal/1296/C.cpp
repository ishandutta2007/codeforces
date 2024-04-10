#include<stdio.h>
#include<map>
using namespace std;
#define R register int
#define P pair<int,int>
map<P,int>Q;
map<P,bool>K;
inline void Solve(){
	Q.clear();
	K.clear();
	int n,mn=1e6,id,x;
	scanf("%d\n",&n);
	char c;
	P Tem;
	Tem.first=0;
	Tem.second=0;
	Q[Tem]=0;
	K[Tem]=true;
	for(R i=1;i<=n;i++){
		c=getchar();
		if(c=='U'){
			Tem.first++;
		}else if(c=='D'){
			Tem.first--;
		}else if(c=='L'){
			Tem.second--;
		}else{
			Tem.second++;
		}
		if(K[Tem]==true){
			x=i-Q[Tem];
			if(x<mn){
				mn=x;
				id=i;
			}
		}else{
			K[Tem]=true;
		}
		Q[Tem]=i;
	}
	if(mn==1e6){
		puts("-1");
	}else{
		printf("%d %d\n",id-mn+1,id);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}