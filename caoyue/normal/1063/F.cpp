#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=5e5+7;
const int INF=1e9+7;
int ra[N],s[N],sa[N],las[N],ns[N],na[N],now[N],lc[N],ht[N];
struct pir{int x,c;}p[N];
char sss[N];
int n,T;
bool cmp(pir a,pir b){return a.c<b.c;}
int go(int d){while(ra[sa[d]]==ra[sa[d+1]])d++; return d;}
void build(){
	rep(i,n)p[i]=(pir){i,s[i]};
	sort(p+1,p+n+1,cmp);
	int nw=1;
	rep(i,n){
		if(i==1||p[i].c!=p[i-1].c)nw=i;
		ra[p[i].x]=nw;
		sa[i]=p[i].x;
	}
	for(int j=1;j<=n;j<<=1){
		memset(las,0,sizeof(las));
		memset(lc,0,sizeof(lc));
		memset(now,0,sizeof(now));
		REP(i,n-j+1,n){
			ns[ra[i]]=i;
			na[i]=ra[i];
			now[ra[i]]++;
			las[ra[i]]++;
		}
		rep(i,n){
			if(sa[i]<=j)continue;
			int b=sa[i]-j;
			now[ra[b]]++;
			if(lc[ra[b]]!=ra[sa[i]]){
				las[ra[b]]=now[ra[b]];
				lc[ra[b]]=ra[sa[i]];
			}
			ns[ra[b]+now[ra[b]]-1]=b;
			na[b]=ra[b]+las[ra[b]]-1;
		}
		rep(i,n)ra[i]=na[i],sa[i]=ns[i];
	}
	int ans=0;
	rep(i,n){
		if(ra[i]==n){ans=0; continue;}
		if(ans)ans--;
		while(s[i+ans]==s[sa[ra[i]+1]+ans])ans++;
		ht[ra[i]]=ans;
	}
}
int c[N],ma[N],in[N];
bool v[N];
int main(){
	scanf("%d",&n);
	scanf("%s",sss+1);
	rep(i,n)s[i]=sss[i]-'a'+1;
	build();
	rep(i,n)v[i]=1;
	T=sqrt(n*2);
	int ans=1;
	REP(i,2,T){
		int hh=0;
		rep(j,n){
			if(ht[j-1]<i-1)hh++;
			in[sa[j]]=hh;
			ma[hh]=0;
		}
		rep(j,n)if(v[j])ma[in[j]]=max(ma[in[j]],j);
		memset(v,0,sizeof(v));
		rep(j,n){
			if(ma[in[j]]>=j+i)v[j]=1;
			if(ma[in[j+1]]>=j+i)v[j]=1;
			if(v[j])ans=i;
		}
		if(ans!=i)break;
	}
	printf("%d\n",ans);
	return 0;
}
//3 aaa
//5 acbba
//7 aaaaaaa