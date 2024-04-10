#include<stdio.h>
#include<map>
using namespace std;
#define R register int
map<int,int>Q;
int pos[200001];
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		pos[x]=i;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		Q[(pos[x]-i+n)%n]++;
	}
	x=1;
	for(map<int,int>::iterator T=Q.begin();T!=Q.end();T++){
		if(T->second>x){
			x=T->second;
		}
	}
	printf("%d",x);
	return 0;
}