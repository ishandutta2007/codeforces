#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+10;
int kkkk;
int t,top1,top2;
struct rec{
	int a,b,c;
}k1[maxn],k2[maxn];
int main(){
	scanf("%d",&t);
	for (int i=1,x,y;i<=t;++i){
		scanf("%d%d",&x,&y);
		if (x>y) k1[++top1]=rec{x,y,i};
		if (x<y) k2[++top2]=rec{x,y,i};
	}
	if (top1>top2){
		sort(k1+1,k1+1+top1,[](const rec &a, const rec &b) {
			return a.a < b.a;
		});
		printf("%d\n",top1);
		for (int i=1;i<=top1;++i) printf("%d ",k1[i].c); 
	} else {
		sort(k2+1,k2+1+top2,[](const rec &a, const rec &b){
			return a.a > b.a;	
		});
		printf("%d\n",top2);
		for (int i=1;i<=top2;++i) printf("%d ",k2[i].c);
	}
}