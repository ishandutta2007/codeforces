#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int> > >dat[1048576];
int n,m,q,k,fa[53][1000003],x[500003],y[500003],c[500003],nxt[500003],tmp[500003],idx[500003],lc[500003],sz[53][1000003];
inline int fnd(int tp,int nw){
	while(fa[tp][nw]!=nw)
		nw=fa[tp][nw];
	return nw;
}
inline void add(int _l,int _r,int l,int r,int k,int C,int IDX){
	if(l>_r||r<_l||_l>_r)
		return;
	if(_l<=l&&r<=_r){
		dat[k].push_back({C,{x[IDX],y[IDX]}});
		return;
	}
	add(_l,_r,l,l+r>>1,k<<1,C,IDX);
	add(_l,_r,l+r+1>>1,r,k<<1|1,C,IDX);
}
void dfs(int nw){
	for(int i=0;i<dat[nw].size();i++){
		int &C=dat[nw][i].first,&X=dat[nw][i].second.first,&Y=dat[nw][i].second.second;
		X=fnd(C,X<<1);Y=fnd(C,Y<<1);
		if(X==(Y^1)){
			C=-1;
			continue;
		}
		if(sz[C][X]<sz[C][Y]||sz[C][X]==sz[C][Y]&&X<Y)
			swap(X,Y);
		sz[C][X]+=sz[C][Y^1];sz[C][X^1]+=sz[C][Y];
		fa[C][Y]=X^1;fa[C][Y^1]=X;
	}
	if(nw>=524288){
		nw^=(1<<19);
		if(nw<q){
			if(fnd(c[nw],x[idx[nw]]<<1)==fnd(c[nw],y[idx[nw]]<<1))
				printf("NO\n");
			else{
				printf("YES\n"); 
				lc[idx[nw]]=c[nw];
			}
			if(lc[idx[nw]]>=0)
				add(nw+1,nxt[nw]-1,0,524287,1,lc[idx[nw]],idx[nw]);
		}
		nw^=(1<<19);
	}else
		dfs(nw<<1),dfs(nw<<1|1);
	for(int i=dat[nw].size()-1;i>=0;i--){
		int C=dat[nw][i].first,X=dat[nw][i].second.first,Y=dat[nw][i].second.second;
		if(C==-1)continue;
		fa[C][Y]=Y;fa[C][Y^1]=Y^1;
		sz[C][X]-=sz[C][Y^1];sz[C][X^1]-=sz[C][Y];
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=0;i<k;i++)
		for(int j=0;j<(n<<1);j++){
			fa[i][j]=j;
			sz[i][j]=1;
		}
	for(int i=0;i<m;i++){
		scanf("%d%d",x+i,y+i);
		x[i]--;y[i]--;
		tmp[i]=q;lc[i]=-1;
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",idx+i,c+i);
		idx[i]--;c[i]--;
	}
	for(int i=q-1;i>=0;i--){
		nxt[i]=tmp[idx[i]];
		tmp[idx[i]]=i;
	}
	dfs(1);
}