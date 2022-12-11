#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int m,n,al[1111][1111],c[1111][1111],qx[1111111],qy[1111111],qc[1111111],qs;
void legal(int x,int y){
	if(al[x][y])return;
	if(x==n||y==m||!x||!y)return;
	int p=0;
	for(int i=x;i<=x+1;++i) for(int j=y;j<=y+1;++j)
		if(c[i][j]) if(!p) p=c[i][j]; else if(p!=c[i][j]) return;
	qs++,qx[qs]=x,qy[qs]=y,qc[qs]=p,al[x][y]=1; //cerr<<x<<' '<<y<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) scanf("%d",&c[i][j]);
	for(int i=1;i<n;++i) for(int j=1;j<m;++j) legal(i,j);
	for(int q=1;q<=qs;++q){
		al[qx[q]][qy[q]]=1;
		for(int i:{0,1}) for(int j:{0,1}) c[qx[q]+i][qy[q]+j]=0;
		for(int i:{-1,0,1}) for(int j:{-1,0,1}) legal(qx[q]+i,qy[q]+j);
	}
	//cerr<<qs<<endl;
	if(qs!=(n-1)*(m-1))return puts("-1"),0;
	printf("%d\n",qs);
	while(qs)printf("%d %d %d\n",qx[qs],qy[qs],qc[qs]?qc[qs]:1),qs--;
}