#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
//prob B

typedef pair<int,int> pii;
#define fr first
#define se second
#define mp make_pair
int n,w,h;
const int MX=100111;
struct P{
	pii p;int v,x,px,id;
	inline bool operator <(const P &a)const{return v<a.v;}
}d[MX];
pii t[MX];
inline bool cmppx(const P &a,const P &b){return a.px<b.px;}
inline bool cmpx(const P &a,const P &b){return a.x<b.x;}
pii ans[MX];
int main(){
	scanf("%d%d%d",&n,&w,&h);
	for(int i=1;i<=n;i++){
		int g,p,t;
		scanf("%d%d%d",&g,&p,&t);
		d[i].id=i;
		d[i].v=p-t;
		d[i].x=(g==1?p+t:-t-p);
		d[i].p=(g==1?mp(p,h):mp(w,p));
		d[i].px=d[i].p.fr-d[i].p.se;
	}
	sort(d+1,d+n+1);
	int j=1;
	for(int i=1;i<=n;i=j){
		for(j=i;j<=n&&d[j].v==d[i].v;j++);
		sort(d+i,d+j,cmppx);
		for(int k=i;k<j;k++)t[k]=d[k].p;
		sort(d+i,d+j,cmpx);
		for(int k=i;k<j;k++)ans[d[k].id]=t[k];
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i].fr,ans[i].se);
	return 0;
}