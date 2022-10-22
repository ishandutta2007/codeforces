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
const int N=1507;
const int M=2e4+7;
const int INF=1e9+7;
const ll mod1=323232323;
const ll mod2=1004535809;
int n,m,cc=0,cnt=0;
int a[N][N],b[N][N],L[M],R[M],dg[M],D[N];
vector<int>w[M],c[N];
struct pir{
	int x,y;
	friend bool operator < (pir a,pir b){return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);}
};
map<pir,int>mp;
bool is[M];

void work(int l,int r){
	if(l>=r)return;
	int mid=(l+r)>>1;
	REP(i,l,mid-1){
		L[++cnt]=i;
		R[cnt]=mid;
	}
	REP(i,mid+1,r){
		L[++cnt]=mid;
		R[cnt]=i;
	}
	work(l,mid-1);
	work(mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n)rep(j,m)scanf("%d",&a[i][j]);
	rep(i,n)rep(j,m)scanf("%d",&b[i][j]);
	rep(i,n){
		ll s1=0,s2=0;
		rep(j,m){
			s1=s1*1989ll+(ll)a[i][j];
			s2=s2*1989ll+(ll)a[i][j];
			s1%=mod1;
			s2%=mod2;
		}
		pir t=(pir){(int)s1,(int)s2};
		if(!mp.count(t)){
			mp[t]=++cc;
			c[cc].clear();
		}
		c[mp[t]].push_back(i);
	}
	for(int i=n;i;i--){
		ll s1=0,s2=0;
		rep(j,m){
			s1=s1*1989ll+(ll)b[i][j];
			s2=s2*1989ll+(ll)b[i][j];
			s1%=mod1;
			s2%=mod2;
		}
		pir t=(pir){(int)s1,(int)s2};
		if(!mp.count(t)){
			puts("-1");
			return 0;
		}
		if(!c[mp[t]].size()){
			puts("-1");
			return 0;
		}
		b[i][m+1]=c[mp[t]][c[mp[t]].size()-1];
		c[mp[t]].pop_back();
	}
	m++;
	work(1,n);
	rep(i,m){
		rep(j,cnt){
			if(b[L[j]][i]>b[R[j]][i]){
				dg[i]++;
				w[j].push_back(i);
			}
		}
	}
	rep(i,m){
		int id=-1;
		for(int j=m;j;j--){
			if(!dg[j]){
				id=j;
				dg[j]=-1;
				break;
			}
		}
		if(id==m){
			printf("%d\n",i-1);
			for(int j=i-1;j;j--)printf("%d ",D[j]);
			puts("");
			return 0;
		}
		D[i]=id;
		rep(j,cnt){
			if(b[L[j]][id]<b[R[j]][id]&&!is[j]){
				is[j]=1;
				for(int k=0;k<w[j].size();k++)dg[w[j][k]]--;
			}
		}
	}
	puts("-1");
	return 0;
}