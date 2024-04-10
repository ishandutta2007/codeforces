#include<bits/stdc++.h>
#define int long long
const int N=100005,P=21;
using namespace std;

int a[N],b[N],d[N],n,m,x,y;
struct node{
	int x,i;
	node operator +(node c){
		return (node){max(x,c.x),min(i,c.i)};
	}
}st[P][N];
int ln[N];
void init(){
	ln[0]=-1;
	for(int i=1;i<N;i++)ln[i]=ln[i>>1]+1;
	for(int i=1;i<=n;i++)
		st[0][i]=(node){d[i],d[i]};
	for(int i=1;i<P;i++)
		for(int j=1;j<=n-(1<<i)+1;j++)
			st[i][j]=st[i-1][j]+st[i-1][j+(1<<i-1)];
}

node qry(int x,int y){
	int z=ln[y-x+1];
	return st[z][x]+st[z][y-(1<<z)+1];
}

main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i],d[i]=b[i]-a[i];
	for(int i=1;i<=n;i++)a[i]+=a[i-1],b[i]+=b[i-1],d[i]+=d[i-1];
	init();
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		node nw=qry(x,y);
		nw.x-=d[x-1],nw.i-=d[x-1];
		if((a[y]-a[x-1])!=(b[y]-b[x-1])||nw.i<0)cout<<-1<<endl;
		else cout<<nw.x<<endl;
	}
}