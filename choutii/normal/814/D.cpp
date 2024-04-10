#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 201234
struct edge{
	int to,nxt;
}e[N];
int cnt,fa[N],lst[N],n,x[N],y[N],r[N],d[N];
void ins(int a,int b){
	e[++cnt]=(edge){b,lst[a]};lst[a]=cnt;
} 
void lnk(int a,int b){
	ins(a,b);
}
void dfs(int x){
	for(int i=lst[x],b;i;i=e[i].nxt){
		d[e[i].to]=d[x]+1;
		dfs(e[i].to);
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d",x+i,y+i,r+i);
	r[0]=1e7;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j!=i){
				if(r[j]>r[i])
					if((ll)(y[j]-y[i])*(y[j]-y[i])+(ll)(x[j]-x[i])*(x[j]-x[i])<=(ll)(r[j]-r[i])*(r[j]-r[i])){
						if(r[j]<r[fa[i]])
							fa[i]=j;
					}
			}
		}
	}
	
	for(i=1;i<=n;i++)if(!fa[i]);else lnk(fa[i],i); 
	for(i=1;i<=n;i++){
	if(!fa[i])
	d[i]=1,
	dfs(i);
	}
    double ans=0.0;
    double pi=acos(-1); 
	for(i=1;i<=n;i++){
		if(d[i]<=2||d[i]%2==0)ans+=pi*r[i]*r[i];
		else ans-=pi*r[i]*r[i];
	}
    printf("%.10lf",ans);
	return 0;
}