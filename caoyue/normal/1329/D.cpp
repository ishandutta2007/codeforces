#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=2e5+7;
const int INF=1e9+7;
int T,n,cnt,sm,tot;
char s[N];
int a[N],w[N],c[26],d[N],f1[N],f2[N],cc[N];
int ff(int x,int *f){return (f[x]==x)?x:f[x]=ff(f[x],f);}
struct pir{
	int x,y;
	friend bool operator < (pir a,pir b){
		return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
	}
};
set<pir>p[27];
struct op{int l,r;}Q[N];
int low(int x){return x&(-x);}
void ins(int x,int v){for(int i=x;i<=n;i+=low(i))cc[i]+=v;}
int check(int x){
	int ans=0;
	for(int i=x;i;i-=low(i))ans+=cc[i];
	return ans;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		tot=cnt=0;
		n=strlen(s+1);
		rep0(i,26)c[i]=0;
		rep(i,n)a[i]=s[i]-'a';
		rep(i,n-1){
			if(a[i]==a[i+1]){
				c[a[i]]++;
				w[++cnt]=i;
				d[cnt]=a[i];
			}
		}
		sm=cnt;
		rep0(i,26)p[i].clear();
		rep(i,cnt-1){
			if(d[i]==d[i+1])continue;
			p[d[i]].insert((pir){i,i+1});
			p[d[i+1]].insert((pir){i,i+1});
		}
		int o=0;
		rep0(i,26)o=max(o,c[i]);
		int as=max((cnt+1)/2,o)+1;
		printf("%d\n",as);
		rep0(i,cnt+1)f1[i]=f2[i]=i;
		rep(i,as-1){
			int mx=0,md=0,ss=0;
			rep0(j,26){
				if(c[j]>=mx){mx=c[j]; md=j;}
				ss+=c[j];
			}
			if(ss!=mx){
				pir g=*p[md].begin();
				Q[++tot]=(op){g.x,g.y};
				p[d[g.x]].erase(g);
				p[d[g.y]].erase(g);
				int of=ff(g.x-1,f1),ob=ff(g.y+1,f2);
				if(of&&d[of]!=d[g.x]){
					p[d[of]].erase((pir){of,g.x});
					p[d[g.x]].erase((pir){of,g.x});
				}
				if(ob!=cnt+1&&d[ob]!=d[g.y]){
					p[d[ob]].erase((pir){g.y,ob});
					p[d[g.y]].erase((pir){g.y,ob});
				}
				if(of&&ob!=cnt+1&&d[ob]!=d[of]){
					p[d[ob]].insert((pir){of,ob});
					p[d[of]].insert((pir){of,ob});
				}
				f1[g.x]=g.x-1;
				f1[g.y]=g.y-1;
				f2[g.x]=g.x+1;
				f2[g.y]=g.y+1;
				c[d[g.x]]--;
				c[d[g.y]]--;
			}
			else{
				int t1=ff(1,f2);
				f1[t1]=t1-1;
				f2[t1]=t1+1;
				Q[++tot]=(op){0,t1};
			}
		}
		rep(i,n)cc[i]=0;
		rep(i,n)ins(i,1);
		rep(i,tot){
			if(!Q[i].l){
				int u=check(w[Q[i].r]);
				printf("%d %d\n",1,u);
				ins(w[Q[i].r]+1,-u);
			}
			else{
				int u=check(w[Q[i].l]+1),v=check(w[Q[i].r]);
				ins(w[Q[i].r]+1,-(v-u+1));
				printf("%d %d\n",u,v);
			}
		}
		printf("%d %d\n",1,check(n));
	}
	return 0;
}