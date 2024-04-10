#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=777777777;
int n,m,cnt;
int dat[3][3][155654];
int mat[3][3];
int L[155654],R[155654];
void add(int &A,int B){
	A+=B;
	if(A>=MOD)A-=MOD;
}
void push(int id){
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)dat[i][j][id]=0;
	for(int j=0;j<3;j++)for(int k=0;k<3;k++)if(mat[j][k])
		for(int i=0;i<3;i++)if(dat[i][j][L[id]])
			for(int l=0;l<3;l++)if(dat[k][l][R[id]])
				add(dat[i][l][id],1ll*dat[i][j][L[id]]*dat[k][l][R[id]]%MOD);
}
int built(int l,int r){
	int id=++cnt;
	if(l==r){
		for(int i=0;i<3;i++)dat[i][i][id]=1;
		return id;
	}
	int mid=(l+r)>>1;
	L[id]=built(l,mid);
	R[id]=built(mid+1,r);
	push(id);
	return id;
}
void upd(int l,int r,int id,int pos,int x){
	if(l==r){
		for(int i=0;i<3;i++)dat[i][i][id]=0;
		if(x==0)for(int i=0;i<3;i++)dat[i][i][id]=1;
		else dat[x-1][x-1][id]=1;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)upd(l,mid,L[id],pos,x);
	else upd(mid+1,r,R[id],pos,x);
	push(id);
}
int x,y;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)scanf("%d",&mat[i][j]);
	built(1,n);
	while(m--){
		scanf("%d%d",&x,&y);
		upd(1,n,1,x,y);
		int ans=0;
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)add(ans,dat[i][j][1]);
		printf("%d\n",ans);
	}
}