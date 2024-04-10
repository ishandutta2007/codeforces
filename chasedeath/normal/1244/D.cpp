#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e5+10;

int n;
int c[4][N];
struct Edge{
	int to,nxt;
}e[N<<1];
int head[N],ecnt,ind[N];
void AddEdge(int u,int v) {
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
	ind[u]++;
}


ll idx,idy,mi=1e18,res;
int ans[N];

void dfs(int u,int f,int a,int b) {
	int t=6-a-b;
	//cout<<"%"<<u<<' '<<t<<endl;
	ans[u]=t;
	res+=c[t][u];
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u,t,a);
	}
}



int main(){ 
	n=rd();
	rep(i,1,3) rep(j,1,n) c[i][j]=rd();
	rep(i,2,n) {
		int u=rd(),v=rd();
		AddEdge(u,v);
		AddEdge(v,u);
	}
	int fl=0;
	rep(i,1,n) if(ind[i]>=3) fl=1;
	if(fl) return puts("-1"),0;
	rep(i,1,n) if(ind[i]==1) {
		int t;
		for(reg int j=head[i];j;j=e[j].nxt) t=e[j].to;
		int v;
		for(reg int j=head[t];j;j=e[j].nxt) if(e[j].to!=i) v=e[j].to;
		//cout<<i<<' '<<t<<' '<<v<<endl;
		//puts("");
		rep(a,1,3) rep(b,1,3) if(a!=b) {
			res=0;
			res+=c[a][i]+c[b][t];
			//cout<<"#"<<a<<' '<<b<<endl;
			dfs(v,t,b,a);
			if(res<mi) mi=res,idx=a,idy=b;
		}
		ans[i]=idx,ans[t]=idy;
		dfs(v,t,idy,idx);
		cout<<mi<<endl;
		ans[i]=idx,ans[t]=idy;
		rep(j,1,n) printf("%d ",ans[j]);
		puts("");
		break;
	}
}