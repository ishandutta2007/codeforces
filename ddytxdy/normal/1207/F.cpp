#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=800;
int q,lim,ans[M][M],a[N];
void change(int x,int y){
	for(int i=1;i<=lim;i++)ans[i][x%i]+=y;
	a[x]+=y;
}
void ask(int x,int y){
	if(x<=lim){printf("%d\n",ans[x][y]);return;}
	int ret=0;
	for(int i=y;i<=500000;i+=x)ret+=a[i];
	printf("%d\n",ret);
}
int main(){
	scanf("%d",&q);lim=sqrt(500000);
	for(int i=1,k,x,y;i<=q;i++){
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)change(x,y);
		else ask(x,y);
	}
	return 0;
}