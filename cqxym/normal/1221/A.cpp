#include<stdio.h>
#include<cmath>
using namespace std;
#define R register int
int p[12];
void Solve(){
	int n,x,y;
	scanf("%d",&n);
	for(R i=0;i<n;i++){
		scanf("%d",&x);
		if(x<2050){
			y=log2(x);
			p[y]++;
		}
	}
	for(R i=0;i<11;i++){
		p[i+1]+=p[i]>>1;
		p[i]=0;
	}
	if(p[11]>0){
		puts("YES");
	}else{
		puts("NO");
	}
	p[11]=0;
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i<t;i++){
		Solve();
	}
	return 0;
}