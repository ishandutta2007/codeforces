#include<bits/stdc++.h>
using namespace std;
const int M=1000000007,E=524288,N=300005;
int t,n,a[N],ans,f[N],siz[1005],s,m,u,v,pos;
struct str{
	long long a[3][3];
}tree[N*4];
char c[N],d;
str operator *(str a,str b){
	str tmp;
	memset(tmp.a,0x7f,sizeof(tmp.a));
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				tmp.a[j][k]=min(tmp.a[j][k],a.a[j][i]+b.a[i][k]);
	return tmp;
}
void modify(int i,int l,int r,int x,char c){
	if(l==r){
		str tmp;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				tmp.a[i][j]=1<<30;
		tmp.a[0][0]=tmp.a[1][1]=tmp.a[2][2]=0;
		if(c=='a'){
			tmp.a[1][2]=0;
			tmp.a[2][2]=1;
		}
		if(c=='b'){
			tmp.a[0][1]=0;
			tmp.a[1][1]=1;
		}
		if(c=='c')
			tmp.a[0][0]=1;
		tree[i]=tmp;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x,c);
	else
		modify(i<<1|1,mid+1,r,x,c);
	tree[i]=tree[i<<1|1]*tree[i<<1];
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	scanf("%s",c+1);
	for(int i=1;i<=n;++i)
		modify(1,1,n,i,c[i]);
	while(m--){
		scanf("%d %c\n",&pos,&d);
		modify(1,1,n,pos,d);
		printf("%lld\n",min({tree[1].a[0][2],tree[1].a[1][2],tree[1].a[2][2]}));
	}
}