#include<bits/stdc++.h>
using namespace std;
int n,x,p[2050],ans[2050][2050];
int getans(int a,int b){
	if(ans[a][b]>0)return ans[a][b];
	printf("? %d %d\n",a,b);
	fflush(stdout);
	scanf("%d",&x);
	ans[a][b]=ans[b][a]=x;
	return x;
}
int main(){
	cin>>n;
	int a=1,b=2,val=getans(1,2),id;
	for(int i=3;i<=n;i++){
		int tmp=getans(i,b);
		if(tmp<val)a=i,val=tmp;
		else if(tmp==val)b=i,val=getans(a,i);
	}
	while(1){
		int X=rand()%n+1;
		if(X==a||X==b)continue;
		int v1=getans(X,a),v2=getans(X,b);
		if(v1!=v2){
			id=(v1<v2?a:b);
			break;
		}
	}
	for(int i=1;i<=n;i++)if(id!=i){
		if(ans[id][i]>0)p[i]=ans[id][i];
		else p[i]=getans(id,i);
	}
	putchar('!'),putchar(' ');for(int i=1;i<=n;i++)printf("%d ",p[i]);
}