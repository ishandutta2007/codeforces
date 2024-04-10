#include<bits/stdc++.h>
using namespace std;
int T=1;
int fa[400003];
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
int tp[200003];
vector<int>ex,ey,ew;
int main(){
	cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<2*n;i++)
			fa[i]=i;ex.clear();ey.clear();ew.clear();
		for(int i=1;i<n;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			x--;y--;
			ex.push_back(x);ey.push_back(y);
			ew.push_back(w);
			if(w!=-1)
				if(__builtin_popcount(w)%2==0)
					fa[fnd(x)]=fnd(y),
					fa[fnd(x+n)]=fnd(y+n);
				else
					fa[fnd(x)]=fnd(y+n),
					fa[fnd(x+n)]=fnd(y);
		}
		for(int i=0;i<m;i++){
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);x--;y--;
			if((w&1)==0)
				fa[fnd(x)]=fnd(y),
				fa[fnd(x+n)]=fnd(y+n);
			else
				fa[fnd(x)]=fnd(y+n),
				fa[fnd(x+n)]=fnd(y);
		}
		bool ok=1;
		for(int i=0;i<n;i++)
			if(fnd(i)==fnd(i+n))
				ok=0;
		if(!ok){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=0;i<n;i++)
			if(fnd(i)==i)
				tp[i]=0;
			else
				tp[i]=(fnd(i)>=n);
		for(int i=0;i<ex.size();i++){
			if(ew[i]==-1)
				ew[i]=tp[ex[i]]^tp[ey[i]];
			printf("%d %d %d\n",ex[i]+1,ey[i]+1,ew[i]);
		}
	}
}