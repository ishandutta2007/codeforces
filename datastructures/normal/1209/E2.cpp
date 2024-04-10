#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;
int t,n,m,aa[15][2005],a[15][15],val[15][10005],f[15][10005];
int d[15];
struct node{
	int val,id;
}c[2005];
inline bool cmp(node a,node b){
	return a.val>b.val;
}
int main(){
	cin>>t;
	while(t--){
		memset(val,0,sizeof(val));
		memset(f,0,sizeof(f));
		cin>>n>>m;
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=m;j++)
				scanf("%d",&aa[i][j]);
		for (register int i=1;i<=m;i++){
			int mx=0;
			for (register int j=1;j<=n;j++)
				mx=max(mx,aa[j][i]);
			c[i].id=i,c[i].val=mx;
		}
		sort(c+1,c+1+m,cmp);
		m=min(n,m);
		for (register int i=1;i<=m;i++){
			for (register int j=1;j<=n;j++)
				a[j][i]=aa[j][c[i].id];
		}
		for (register int i=1;i<=m;i++){
			for (register int j=1;j<=n;j++){
				int tot=0;
				for (register int k=j;k<=n;k++)d[++tot]=a[k][i];
				for (register int k=1;k<j;k++)d[++tot]=a[k][i];
				for (register int k=0;k<(1<<n);k++){
					int s=0;
					for (register int l=1;l<=tot;l++)
						if ((k&(1<<(l-1)))!=0)s+=d[l];
					val[i][k]=max(val[i][k],s); 
				}
			}
		}
		for (register int i=1;i<=m;i++)
			for (register int j=0;j<(1<<n);j++){
				f[i][j]=val[i][j];
				for (register int k=j;k;k=(k-1)&j)
					f[i][j]=max(f[i][j],f[i-1][k]+val[i][j^k]);
			}
		cout<<f[m][(1<<n)-1]<<endl;
	}
	return 0;
}