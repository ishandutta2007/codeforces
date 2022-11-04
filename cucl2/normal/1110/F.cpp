#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define INT long long
#define Inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fLL
#define SZ(s) ((s).size())

struct{
	INT dt[8000005],wp[8000005];
	void plus(int now,int nl,int nr,int l,int r,INT x){
		if(l>r){
			return;
		}
		if(wp[now]){
			dt[now<<1]+=wp[now];
			dt[now<<1|1]+=wp[now];
			wp[now<<1]+=wp[now];
			wp[now<<1|1]+=wp[now];
			wp[now]=0;
		}
		if(nl>=l&&nr<=r){
			dt[now]+=x;
			wp[now]+=x;
			return;
		}
		if(nl>r||nr<l){
			return;
		}
		int m=(nl+nr)>>1;
		plus(now<<1,nl,m,l,r,x);
		plus(now<<1|1,m+1,nr,l,r,x);
		dt[now]=min(dt[now<<1],dt[now<<1|1]);
	}
	INT qmin(int now,int nl,int nr,int l,int r){
		if(wp[now]){
			dt[now<<1]+=wp[now];
			dt[now<<1|1]+=wp[now];
			wp[now<<1]+=wp[now];
			wp[now<<1|1]+=wp[now];
			wp[now]=0;
		}
		if(nl>=l&&nr<=r){
			return dt[now];
		}
		if(nl>r||nr<l){
			return INF;
		}
		int m=(nl+nr)>>1;
		return min(qmin(now<<1,nl,m,l,r),qmin(now<<1|1,m+1,nr,l,r));
	}
}seg;

vector<pair<int,int> > nei[500005];
int wht=0,en[500005];
int n,q;
vector<pair<int,int> > qry[500005];
vector<int> whrq[500005];
INT ans[500005];

void dfs1(int now,INT len){
	wht++;
	bool upd=0;
	for(int i=0;i<SZ(nei[now]);i++){
		dfs1(nei[now][i].first,nei[now][i].second+len);
		upd=1;
	}
	en[now]=wht;
	if(!upd){
		seg.plus(1,1,n,now,now,len);
	}else{
		seg.plus(1,1,n,now,now,INF);
	}
}

void dfs2(int now,int len){
	seg.plus(1,1,n,now,en[now],-len);
	seg.plus(1,1,n,1,now-1,len);
	seg.plus(1,1,n,en[now]+1,n,len);
	//cerr<<now<<' '<<en[now]<<' '<<len<<endl;
	for(int i=0;i<SZ(qry[now]);i++){
		ans[whrq[now][i]]=seg.qmin(1,1,n,qry[now][i].first,qry[now][i].second);
		//cerr<<' '<<whrq[now][i]<<' '<<seg.qmin(1,1,n,qry[now][i].first,qry[now][i].second)<<endl;
	}
	for(int i=0;i<SZ(nei[now]);i++){
		dfs2(nei[now][i].first,nei[now][i].second);
	}
	seg.plus(1,1,n,now,en[now],len);
	seg.plus(1,1,n,1,now-1,-len);
	seg.plus(1,1,n,en[now]+1,n,-len);
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(make_pair(i,b));
	}
	dfs1(1,0);
	for(int i=0;i<q;i++){
		int v,l,r;
		scanf("%d%d%d",&v,&l,&r);
		qry[v].push_back(make_pair(l,r));
		whrq[v].push_back(i);
	}
	dfs2(1,0);
	for(int i=0;i<q;i++){
		printf("%I64d\n",ans[i]);
	}
	return 0;
}