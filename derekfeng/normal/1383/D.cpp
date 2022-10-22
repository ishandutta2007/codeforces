#include <bits/stdc++.h>
using namespace std;
int n,m;
int R[253],C[253];
int a[253][253],ans[253][253];
int inv1[62503],inv2[62503];
queue<int>q1,q2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]),R[i]=max(R[i],a[i][j]),C[j]=max(C[j],a[i][j]),inv1[a[i][j]]=i,inv2[a[i][j]]=j;
	int N=0,M=0;
	for(int i=n*m;i;i--){
		int x=inv1[i],y=inv2[i];
		bool f1=0,f2=0;
		if(R[x]==a[x][y])f1=1;
		if(C[y]==a[x][y])f2=1;
		if(f1)N++;
		if(f2)M++;
		if(f1||f2){
			ans[N][M]=i;
			if(f1)for(int j=M-1;j;j--)q1.push(N),q2.push(j);
			if(f2)for(int j=N-1;j;j--)q1.push(j),q2.push(M); 
		}else{
			ans[q1.front()][q2.front()]=i;
			q1.pop(),q2.pop();
		}
	}
	for(int i=1;i<=n;i++,puts(""))for(int j=1;j<=m;j++)printf("%d ",ans[i][j]);
}