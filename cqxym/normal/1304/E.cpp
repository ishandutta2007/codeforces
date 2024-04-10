#include<stdio.h>
#define R register int
#define I inline
const int N=100001,M=200001;
int Last[N],Next[M],End[M],f[N][17],dep[N],ct;
I void Link(int &x,int &y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
I void DFS(int x,int F){
	f[x][0]=F;
	dep[x]=dep[F]+1;
	for(R i=1;i!=17;i++){
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(R i=Last[x];i!=0;i=Next[i]){
		if(End[i]!=F){
			DFS(End[i],x);
		}
	}
}
I void GoUp(int &x,int l){
	for(R i=0;i!=17;i++){
		if((l>>i&1)==1){
			x=f[x][i];
		}
	}
}
I int LCA(int x,int y){
	if(dep[x]<dep[y]){
		int tem=x;
		x=y;
		y=tem;
	}
	GoUp(x,dep[x]-dep[y]);
	if(x==y){
		return y;
	}
	for(R i=16;i!=-1;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
I int Dis(int x,int y){
	return dep[x]+dep[y]-(dep[LCA(x,y)]<<1);
}
I bool Check(int x,int y){
	return x<=y&&((x^y)&1)==0;
}
int main(){
	int n,x,y,a,b,k;
	scanf("%d",&n);
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		Link(x,y);
		Link(y,x);
	}
	DFS(1,0);
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d%d%d%d%d",&x,&y,&a,&b,&k);
		if(Check(Dis(a,b),k)==true||Check(Dis(a,x)+1+Dis(y,b),k)==true||Check(Dis(a,y)+1+Dis(b,x),k)==true){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}