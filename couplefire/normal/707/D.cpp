#include<bits/stdc++.h>
#define N 1005
#define M 100005
using namespace std;
int tot,n,m,q;
int a[N][N],s[N],rev[N];
vector<int> v[M];
int flag[M],op[M];
int x[M],y[M],z[M];
void dfs(int k){
	if(op[k]==1)
		if(a[x[k]][y[k]]^rev[x[k]]^1){
			flag[k]=1;
			++s[x[k]];
			++tot;
			a[x[k]][y[k]]^=1;
		}
	if(op[k]==2)
		if(a[x[k]][y[k]]^rev[x[k]]){
			flag[k]=1;
			--s[x[k]];
			--tot;
			a[x[k]][y[k]]^=1;
		}
	if(op[k]==3){
		tot+=m-s[x[k]]*2;
		rev[x[k]]^=1;
		s[x[k]]=m-s[x[k]];
	}
	z[k]=tot;
	for(int i=0;i!=v[k].size();++i)
		dfs(v[k][i]);
	if(op[k]==2&&flag[k]){
		++s[x[k]];
		++tot;
		a[x[k]][y[k]]^=1;
	}
	if(op[k]==1&&flag[k]){
		--s[x[k]];
		--tot;
		a[x[k]][y[k]]^=1;
	}
	if(op[k]==3){
		tot+=m-s[x[k]]*2;
		rev[x[k]]^=1;
		s[x[k]]=m-s[x[k]];
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;++i){
		scanf("%d%d",op+i,x+i);
		if(op[i]<3)
			scanf("%d",y+i);
		if(op[i]!=4)
			v[i-1].push_back(i);
		else
			v[x[i]].push_back(i);
	}
	dfs(0);
	for(int i=1;i<=q;++i)
		printf("%d\n",z[i]);
}