#include <cstdio>
#include <iostream>
#include <cstring>
#include <set>
#include <map>
using namespace std;

struct{
	int dt[1600005];
	void init(){
		memset(dt,-1,sizeof(dt));
	}
	void upd(int now,int nl,int nr,int to,int x){
		if(nl==to&&nr==to){
			dt[now]=x;
			return;
		}
		int m=(nl+nr)>>1;
		if(m>=to){
			upd(now<<1,nl,m,to,x);
		}else{
			upd(now<<1|1,m+1,nr,to,x);
		}
		dt[now]=max(dt[now<<1],dt[now<<1|1]);
	}
	int find(int now,int nl,int nr,int l,int x){
		if(nr<l){
			return -1;
		}
		if(dt[now]<x){
			return -1;
		}
		if(nl==nr){
			return nl;
		}
		int m=(nl+nr)>>1;
		int X=find(now<<1,nl,m,l,x);
		if(X==-1){
			X=find(now<<1|1,m+1,nr,l,x);
		}
		return X;
	}
}seg;

set<int> st[200005];
int n;
int op[200005],x[200005],y[200005];
char Tmp[10];
map<int,int> dx;
int xd[200005],Cntdx;

int main(){
	seg.init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",Tmp);
		if(Tmp[0]=='a'){
			op[i]=0;
		}else if(Tmp[0]=='r'){
			op[i]=1;
		}else{
			op[i]=2;
		}
		scanf("%d%d",x+i,y+i);
		dx[x[i]];
	}
	for(map<int,int>::iterator it=dx.begin();it!=dx.end();it++){
		xd[Cntdx]=it->first;
		it->second=Cntdx++;
	}
	for(int i=0;i<n;i++){
		x[i]=dx[x[i]];
		if(op[i]==0){
			st[x[i]].insert(y[i]);
			set<int>::iterator it=st[x[i]].end();
			it--;
			seg.upd(1,0,Cntdx-1,x[i],*it);
		}else if(op[i]==1){
			st[x[i]].erase(y[i]);
			if(st[x[i]].size()){
				set<int>::iterator it=st[x[i]].end();
				it--;
				seg.upd(1,0,Cntdx-1,x[i],*it);
			}else{
				seg.upd(1,0,Cntdx-1,x[i],-1);
			}
		}else{
			int xx=seg.find(1,0,Cntdx-1,x[i]+1,y[i]+1);
			if(xx==-1){
				printf("-1\n");
				continue;
			}
			int yy=*st[xx].lower_bound(y[i]+1);
			printf("%d %d\n",xd[xx],yy);
		}
	}
	return 0;
}