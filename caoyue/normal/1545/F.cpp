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
const int M=1077;
const int INF=1e9+7;
int n,m,m1=0,m2=0;
int a[N],b[N],c[N],p[N][3],xw[N],R[N],K[N],X[N],zr[N],zd[N],zw[M],q[M][3],nq[M],fr[N],bg[3][N],ed[3][N],ss[3][N];
ll w[3][N],sb[M],sc[M],sf[N],ba[M],Ans[N];
vector<pair<int,int> >h[M];
int s[N*20];
void work(){
	memset(w,0,sizeof(w));
	memset(fr,0,sizeof(fr));
	int oo=0;
	sf[0]=0;
	rep0(i,3)memcpy(ed[i],bg[i],sizeof(int)*(n+3));
	rep(j,n){
		if(!p[j][0]){
			oo++;
			for(int j=0;j<h[oo].size();j++)Ans[h[oo][j].second]+=w[1][h[oo][j].first];
			w[2][j]=w[2][j-1];
		}
		else{
			sf[j]=sf[fr[p[j][2]]]+ed[1][p[j][2]]-bg[1][p[j][2]];
			fr[p[j][2]]=j;
			w[2][j]=w[2][j-1]+w[1][p[j][2]];
			w[1][p[j][1]]+=w[0][p[j][1]];
			w[0][p[j][0]]++;
			rep0(i,3)s[ed[i][p[j][i]]++]=j;
		}
	}
}
inline int qf(int k,int x,int y){return lower_bound(s+bg[k][x],s+ed[k][x],y)-s-bg[k][x];}
inline int qe(int k,int x,int y){return s+ed[k][x]-upper_bound(s+bg[k][x],s+ed[k][x],y);}

int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,n)scanf("%d",&b[i]);
	rep(i,n)scanf("%d",&c[i]);
	rep(i,n){
		p[i][1]=a[i];
		p[i][0]=b[a[i]];
		p[i][2]=c[a[i]];
		ss[0][b[a[i]]]++;
		ss[1][a[i]]++;
		ss[2][c[a[i]]]++;
	}
	K[++m1]=1;
	X[1]=a[1];
	rep(i,m){
		int op,x; scanf("%d%d",&op,&x);
		if(op&1){
			K[++m1]=x;
			scanf("%d",&X[m1]);
			ss[0][b[X[m1]]]++;
			ss[1][X[m1]]++;
			ss[2][c[X[m1]]]++;
		}
		else{
			xw[++m2]=m1;
			R[m2]=x;
		}
	}
	int tot=0;
	rep0(i,3){
		rep(j,n){
			bg[i][j]=tot;
			tot+=ss[i][j];
		}
	}
	int nw=1,T;
	if(m<=500)T=sqrt(m1);
	else {
		if(m1<=m2)T=250;
		else{
			ll mh=70ll*n*m1;
			rep(i,n){
				ll p=i;
				if(p*p*p*m2>mh){
					T=i;
					break;
				}
			}
			T=min(T,1000);
		}
	}
	for(int l=1;l<=m1;l+=T){
		int r=min(m1,l+T-1),cc=0;
		REP(j,l,r){
			if(zr[K[j]]!=l){
				zr[K[j]]=l;
				zw[++cc]=K[j];
			}
		}
		sort(zw+1,zw+cc+1);
		rep(j,cc){
			zd[zw[j]]=j;
			rep0(i,3){
				q[j][i]=p[zw[j]][i];
				p[zw[j]][i]=0;
			}
			nq[j]=q[j][2];
			h[j].clear();
		}
		int nw0=nw;
		REP(j,l,r){
			nq[zd[K[j]]]=c[X[j]];
			while(nw0<=m2&&xw[nw0]==j){
				rep(k,cc){
					if(zw[k]>R[nw0])break;
					h[k].push_back(make_pair(nq[k],nw0));
				}
				nw0++;
			}
		}
		work();
		REP(j,l,r){
			int d=zd[K[j]];
			q[d][0]=b[X[j]];
			q[d][1]=X[j];
			q[d][2]=c[X[j]];
			while(nw<=m2&&xw[nw]==j){
				Ans[nw]+=w[2][R[nw]];
				rep(k,cc){
					if(zw[k]>R[nw])break;
					ll t1=qf(2,q[k][0],zw[k]+1),t2=qf(2,q[k][0],R[nw]+1),t0=qf(1,q[k][0],zw[k]);
					ba[k]=t0;
					if(t1!=t2)Ans[nw]=Ans[nw]-t0*(t2-t1)+sf[s[bg[2][q[k][0]]+t2-1]]-(t1?sf[s[bg[2][q[k][0]]+t1-1]]:0);
					sb[k]=qf(0,q[k][1],zw[k]);
					sc[k]=qe(2,q[k][1],zw[k])-qe(2,q[k][1],R[nw]);
					ll tt=qf(1,q[k][2],zw[k]);
					rep(i,k-1){
						sb[k]+=(q[i][0]==q[k][1]);
						sc[i]+=(q[i][1]==q[k][2]);
						if(q[k][2]==q[i][0])Ans[nw]+=(tt-ba[i]);
					}
				}
				rep(k,cc){
					if(zw[k]>R[nw])break;
					Ans[nw]+=sb[k]*sc[k];
				}
				nw++;
			}
		}
		rep(j,cc)rep0(k,3)p[zw[j]][k]=q[j][k];
	}
	rep(i,m2)printf("%lld\n",Ans[i]);
	return 0;
}