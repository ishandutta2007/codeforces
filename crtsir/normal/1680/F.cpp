#include<bits/stdc++.h>
using namespace std;
int n,m,T,fa[1000003],x[1000003],y[1000003];
int fnd(int X){if(fa[X]!=X)fa[X]=fnd(fa[X]);return fa[X];}
vector<int>v[1000003],g[1000003];
bool cir[1000003],col[1000003];
int pa[1000003][21],dep[1000003];
void painting(int X,int p,int cc){
	col[X]=cc;pa[X][0]=p;
	for(int i=0;i<v[X].size();i++)
		if(v[X][i]!=p)
			dep[v[X][i]]=dep[X]+1,
			painting(v[X][i],X,cc^1);
}
int lca(int X,int Y){
	if(dep[X]<dep[Y])swap(X,Y);
	for(int i=19;i>=0;i--)
		if(dep[X]-dep[Y]&(1<<i))
			X=pa[X][i];
	for(int i=19;i>=0;i--)
		if(pa[X][i]!=pa[Y][i])
			X=pa[X][i],Y=pa[Y][i];
	if(X==Y)return X;
	return pa[X][0];
}
int ban[1000003],lzy[1000003],can,cnt;
void sum(int X,int p){
	for(int i=0;i<v[X].size();i++)
		if(v[X][i]!=p){
			sum(v[X][i],X);
			ban[X]+=ban[v[X][i]];
			lzy[X]+=lzy[v[X][i]];
			if(!ban[v[X][i]]&&lzy[v[X][i]]==cnt)
				can=g[X][i];
		}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			v[i].clear(),fa[i]=i,ban[i]=0,lzy[i]=0,g[i].clear();
		for(int i=0;i<m;i++){
			scanf("%d%d",x+i,y+i);x[i]--;y[i]--;
			if(fnd(x[i])!=fnd(y[i])){
				fa[fnd(x[i])]=fnd(y[i]);
				v[x[i]].push_back(y[i]);
				g[x[i]].push_back(i);
				v[y[i]].push_back(x[i]);
				g[y[i]].push_back(i);
				cir[i]=0;
			}else
				cir[i]=1;
		}dep[0]=0;
		painting(0,-1,0);
		for(int i=1;i<21;i++)
			for(int j=0;j<n;j++)
				if(pa[j][i-1]==-1)
					pa[j][i]=-1;
				else
					pa[j][i]=pa[pa[j][i-1]][i-1];
		can=-1;cnt=0;
		for(int i=0;i<m;i++)
			if(cir[i]){
				int X=x[i],Y=y[i],Z=lca(x[i],y[i]);
				if(col[X]^col[Y]){
					ban[X]++;ban[Y]++;
					if(Z)ban[Z]-=2;
				}else{
					lzy[X]++;lzy[Y]++;
					if(Z)lzy[Z]-=2;
					cnt++;
					if(cnt==1)
						can=i;
					else
						can=-1;
				}
			}
		sum(0,-1);
		for(int i=0;i<n;i++)
			fa[i]=i,v[i].clear();
		if(cnt&&can==-1){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=0;i<m;i++)
			if(can!=i||cnt==0)
				if(fnd(x[i])!=fnd(y[i])){
					fa[fnd(x[i])]=fnd(y[i]);
					v[x[i]].push_back(y[i]);
					v[y[i]].push_back(x[i]);
				}
		painting(x[can],-1,1);
		for(int i=0;i<n;i++)
			if(col[i])
				putchar('1');
			else
				putchar('0');
		printf("\n");
	}
}