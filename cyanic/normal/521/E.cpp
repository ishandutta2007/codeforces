#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define mp make_pair
using namespace std;

const int N=200005;
int f[N],fa[N],x[N],y[N],res[N];
int n,m,a,b,c,d,F,A,B;
vector<int> e[N],ans;

void dfs(int u){
	if(F)return;
	for(auto v:e[u]){
		if(v==fa[u])continue;
		if(!f[v])f[v]=f[u]+1,fa[v]=u,dfs(v);
		else if(f[v]<f[u]){
			for(int s=u;s!=v;s=fa[s]){
				if(x[s]){
					a=x[s],b=y[s],c=u,d=v;
					F=1; return;
				}
				x[s]=u,y[s]=v;
			}
		}
	}
}

map<pair<int,int>,int> R;
int dfs(int u,int k){
	res[u]=0;
	if(u==B)return ans.pb(u),1;
	for(auto v:e[u])
		if(!R[mp(u,v)]&&res[v]==k&&dfs(v,k))
			return ans.pb(u),R[mp(u,v)]=1,R[mp(v,u)]=1,1;
	return 0;
}
void doit(int k){
	ans.clear(),res[B]=k,dfs(A,k);
	printf("%d",(int)ans.size());
	for(auto x:ans)printf(" %d",x);
	puts("");
}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&a,&b);
		e[a].pb(b),e[b].pb(a);
	}
	rep(u,1,n)if(!f[u])f[u]=1,dfs(u);
	if(!F)return puts("NO"),0;
	for(int x=a;f[x]>=f[b];x=fa[x]) res[x]|=1;
	for(int x=c;f[x]>=f[d];x=fa[x]){
		res[x]|=2;
		if(res[x]==3)A=(!A?x:A),B=x;
	}
	puts("YES");
	int c[4]={0,0,0,0},p[4]={0,1,2,3};
	rep(i,1,n)c[res[i]]++; c[3]-=2;
	sort(p+1,p+4,[&](int a,int b){return c[a]<c[b];});
	rep(k,1,3)doit(p[k]);
	return 0;
}