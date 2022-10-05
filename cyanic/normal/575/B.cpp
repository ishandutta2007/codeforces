#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=200005,M=N*2,mod=1e9+7;
struct gragh{
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,k,a[N],b[N],x[N];
int size[N],fa[N],son[N],top[N],depth[N],p[N],cnp=0;
int v1[N],v2[N],t1[N],t2[N],mi[N*10];
void Get_Gen_Info(int rt,int pre,int d){
	fa[rt]=pre,depth[rt]=d,son[rt]=0,size[rt]=1;
	for (int i=g.fst[rt];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			int s=g.y[i];
			Get_Gen_Info(s,rt,d+1);
			size[rt]+=size[s];
			if (!son[rt]||size[s]>size[son[rt]])
				son[rt]=s;
		}
}
void Get_Top(int rt,int tp){
	top[rt]=tp,p[rt]=++cnp;
	if (!son[rt])
		return;
	Get_Top(son[rt],tp);
	for (int i=g.fst[rt];i;i=g.nxt[i]){
		int s=g.y[i];
		if (s!=fa[rt]&&s!=son[rt])
			Get_Top(s,s);
	}
}
void update(int a,int b){
	int f1=top[a],f2=top[b],rev=0;
	while (f1!=f2){
		if (depth[f1]<depth[f2])
			swap(f1,f2),swap(a,b),rev^=1;
		if (rev)
			v1[p[f1]]++,v1[p[a]+1]--;
		else
			v2[p[f1]]++,v2[p[a]+1]--;
		a=fa[f1],f1=top[a];
	}
	if (depth[a]>depth[b])
		swap(a,b),rev^=1;
	if (rev)
		v2[p[a]]++,v2[p[b]+1]--;
	else
		v1[p[a]]++,v1[p[b]+1]--;
}
int main(){
	scanf("%d",&n);
	g.clear();
	for (int i=1;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&x[i]);
		g.add(a[i],n+i),g.add(n+i,a[i]);
		g.add(b[i],n+i),g.add(n+i,b[i]);
	}
	memset(v1,0,sizeof v1);
	memset(v2,0,sizeof v2);
	memset(t1,0,sizeof t1);
	memset(t2,0,sizeof t2);
	Get_Gen_Info(1,0,0);
	Get_Top(1,1);
	for (int i=1;i<=n*2-1;i++)
		if (son[fa[i]]!=i)
			for (int j=i;j;j=son[j])
				if (j>n){
					int w=j-n;
					if (x[w]){
						if (fa[j]==a[w])
							t2[p[j]]=1;
						else
							t1[p[j]]=1;
					}
				}
	scanf("%d",&k);
	mi[0]=0;
	for (int i=1;i<=k;i++)
		mi[i]=(mi[i-1]*2+1)%mod;
	int last=1,x;
	while (k--){
		scanf("%d",&x);
		update(last,x);
		last=x;
	}
	int ans=0;
	for (int i=1;i<=n*2-1;i++){
		v1[i]+=v1[i-1],ans=(ans+t1[i]*mi[v1[i]])%mod;
		v2[i]+=v2[i-1],ans=(ans+t2[i]*mi[v2[i]])%mod;
	}
/*	for (int i=1;i<=n*2-1;i++)
		printf("%d:%d\n",i,p[i]);
	for (int i=1;i<=n*2-1;i++)
		printf("|%d*%d|%d*%d|\n",t1[i],mi[v1[i]],t2[i],mi[v2[i]]);*/
	printf("%d",ans);
	return 0;
}