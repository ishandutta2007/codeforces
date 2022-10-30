#include<bits/stdc++.h>
const int N=200005,M=70;
using namespace std;

int a[M][N],n,m,p,x[N],y[N],u[N],ans,fa[N];

int cbt(int k){
	int ans=0;
	while(k)ans+=k&1,k>>=1;
	return ans;
}

int main(){
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[j][i]);
	for(int i=1;i<=80;i++){
		int nw=((rand()*1<<16)|rand())%n+1,c=0;
		memset(y,0,sizeof(y));
		for(int j=1;j<=m;j++)
			if(a[j][nw])
				x[c++]=j,y[j]=c;
		memset(u,0,sizeof(u));
		for(int j=1;j<=n;j++){
			int l=0;
			for(int k=0;k<c;k++)
				if(a[x[k]][j])
					l|=1<<k;
			u[(1<<c)-1-l]++;
		}
		for(int i=0;i<c;i++)
			for(int j=0;j<1<<c;j++)
				if(j>>i&1)
					u[j]+=u[j-(1<<i)];
		for(int j=0;j<1<<c;j++)
			if(u[j]>=(n+1)/2&&ans<c-cbt(j)){
				ans=c-cbt(j);
				memset(fa,0,sizeof(fa));
				for(int k=0;k<c;k++)
					if(j>>k&1)
						fa[x[k]]=0;
					else fa[x[k]]=1;
			}
//		printf(" %d \n",nw);
	}
	for(int i=1;i<=m;i++)printf("%d",fa[i]);
}