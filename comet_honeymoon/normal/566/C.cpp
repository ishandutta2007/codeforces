#include<bits/stdc++.h>
using namespace std;

int N;
int w[200005];

int lnk[200005];
int pre[400005],tgt[400005],val[400005],cnt;
void add_E(int u,int v,int c){
	pre[++cnt]=lnk[u],tgt[cnt]=v,val[cnt]=c,lnk[u]=cnt;
}

bool used[200005];
int rt;
int s[200005],f[200005];
void Get_siz(int x,int fa){
	s[x]=1;
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=fa&&!used[tgt[e]])
		Get_siz(tgt[e],x),s[x]+=s[tgt[e]];
}
void Get_rt(int x,int fa,int S){
	f[x]=S-s[x];
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=fa&&!used[tgt[e]])
		Get_rt(tgt[e],x,S),f[x]=max(f[x],s[tgt[e]]);
	if(f[x]<f[rt]) rt=x;
}
double Delta[200005],sumval,ans=4e20;int anspos;
void Get_dis(int x,int fa,int dis,int y){
	sumval+=w[x]*pow(dis,1.5),Delta[y]+=w[x]*1.5*pow(dis,0.5);
	for(int e=lnk[x];e;e=pre[e])if(tgt[e]!=fa)
		Get_dis(tgt[e],x,dis+val[e],y);
}
void DFZ(int x){
//	printf("%d\n",x);
	used[x]=1;
	sumval=0;
	double SDelta=0;
	for(int e=lnk[x];e;e=pre[e])
		Delta[tgt[e]]=0,Get_dis(tgt[e],x,val[e],tgt[e]),SDelta+=Delta[tgt[e]];
	if(sumval<ans) ans=sumval,anspos=x;
	for(int e=lnk[x];e;e=pre[e]) if(!used[tgt[e]])
		if(SDelta-2*Delta[tgt[e]]<0){
//			printf("%.8lf\n",SDelta-2*Delta[tgt[e]]);
			rt=0;Get_rt(tgt[e],x,s[tgt[e]]);
			Get_siz(rt,x);
			DFZ(rt);
			break;
		}
}

int main(){
	f[0]=0x3f3f3f3f;
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&w[i]);
	for(int i=1;i<N;i++){
		int u,v,c;scanf("%d%d%d",&u,&v,&c);
		add_E(u,v,c);add_E(v,u,c);
	}
	rt=0;Get_siz(1,1);
	Get_rt(1,1,N);
	DFZ(rt);
	printf("%d %.7lf\n",anspos,ans);
}