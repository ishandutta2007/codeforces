#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 300001
#define S 550
vector<int>G[N];
int a[N],pos[600001],b[S],dep[N],in[N],out[N],ans[N],h[N],ct[N],f[N],Top[N],sz[N];
bool tag[N],vc[N];
struct Query{
	int lf,rt,Start,End,id,Ql,Qr;
	I friend bool operator<(Query x,Query y){
		if(x.lf/S!=y.lf/S){
			return x.lf<y.lf;
		}
		return x.rt<y.rt;
	}
}q[N];
I void PreDFS(R x,R F,int&ct){
	ct++;
	pos[ct]=x;
	sz[x]=1;
	in[x]=ct;
	dep[x]=dep[F]+1;
	f[x]=F;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		if(*T!=F){
			PreDFS(*T,x,ct);
			sz[x]+=sz[*T];
			if(sz[*T]>sz[h[x]]){
				h[x]=*T;
			}
		}
	}
	ct++;
	out[x]=ct;
	pos[ct]=x;
}
I void ReDFS(R x,R t){
	Top[x]=t;
	if(h[x]!=0){
		ReDFS(h[x],t);
		for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
			if(*T!=f[x]&&*T!=h[x]){
				ReDFS(*T,*T);
			}
		}
	}
}
I int LCA(R x,R y){
	while(Top[x]!=Top[y]){
		if(dep[Top[x]]>dep[Top[y]]){
			x=f[Top[x]];
		}else{
			y=f[Top[y]];
		}
	}
	return dep[x]<dep[y]?x:y;
}
I void Add(int x){
	vc[x]^=true;
	if(vc[x]==true){
		b[x/S]++;
	}else{
		b[x/S]--;
	}
}
I int GetAns(int l,int r){
	int bl=l/S,br=r/S;
	if(bl==br){
		for(R i=l;i<=r;i++){
			if(vc[i]==true){
				return i;
			}
		}
		return-1;
	}
	for(R i=bl+1;i!=br;i++){
		if(b[i]!=0){
			for(R j=i*S;j!=(i+1)*S;j++){
				if(vc[j]==true){
					return j;
				}
			}
		}
	}
	for(R i=l;i!=(bl+1)*S;i++){
		if(vc[i]==true){
			return i;
		}
	}
	for(R i=br*S;i<=r;i++){
		if(vc[i]==true){
			return i;
		}
	}
	return-1;
}
int main(){
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i!=n;i++){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	x=0;
	PreDFS(1,0,x);
	ReDFS(1,1);
	for(R i=0;i!=m;i++){
		scanf("%d%d%d%d",&q[i].Start,&q[i].End,&q[i].Ql,&q[i].Qr);
		R st=q[i].Start,ed=q[i].End;
		R t=LCA(st,ed);
		q[i].id=i;
		if(t==st){
			q[i].lf=in[t];
			q[i].rt=in[ed];
		}else if(t==ed){
			q[i].lf=in[t];
			q[i].rt=in[st];
		}else if(out[st]<in[ed]){
			q[i].lf=out[st];
			q[i].rt=in[ed];
		}else{
			q[i].lf=out[ed];
			q[i].rt=in[st];
		}
	}
	sort(q,q+m);
	R l=1,r=0;
	for(R i=0;i!=m;i++){
		R tem,curr=q[i].rt,curl=q[i].lf;
		while(r<curr){
			++r;
			tem=pos[r];
			Add(a[tem]);
			tag[tem]^=true;
		}
		while(l>curl){
			--l;
			tem=pos[l];
			Add(a[tem]);
			tag[tem]^=true;
		}
		while(r>curr){
			tem=pos[r];
			Add(a[tem]);
			tag[tem]^=true;
			--r;
		}
		while(l<curl){
			tem=pos[l];
			Add(a[tem]);
			tag[tem]^=true;
			++l;
		}
		R lca=LCA(q[i].Start,q[i].End);
		if(lca!=q[i].Start&&q[i].End!=lca){
			Add(a[lca]);
			ans[q[i].id]=GetAns(q[i].Ql,q[i].Qr);
			Add(a[lca]);
		}else{
			ans[q[i].id]=GetAns(q[i].Ql,q[i].Qr);
		}
	}
	for(R i=0;i!=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}