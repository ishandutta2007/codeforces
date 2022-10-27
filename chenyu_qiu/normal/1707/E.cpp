#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
inline pii operator+(const pii& x,const pii& y){return mp(min(x.F,y.F),max(x.S,y.S));} 
int n,a[N],q,lg[N];
pii f[20][20][N];//f[k][j][i]i2^j(k+1)(l,r)
pii qry(int k,int l,int r){
	if(l>r) return mp(a[l],a[l]);
	int t=lg[r-l+1];
	return f[k][t][l]+f[k][t][(r-(1<<t)+1)];
} 
int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	n--;lg[0]=-1;
	for(int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++) f[0][0][i]=mp(min(a[i],a[i+1]),max(a[i],a[i+1]));
	for(int j=1;j<=lg[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[0][j][i]=f[0][j-1][i]+f[0][j-1][i+(1<<(j-1))];
	for(int k=1;k<=19;k++){
		for(int i=1;i<=n;i++)
			f[k][0][i]=qry(k-1,f[k-1][0][i].F,f[k-1][0][i].S-1);
		for(int j=1;j<=lg[n];j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				f[k][j][i]=f[k][j-1][i]+f[k][j-1][i+(1<<(j-1))];
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		if(x==1&&y==n+1){
			cout<<0<<endl;
			continue;
		}
		if(x==y){
			cout<<-1<<endl;
			continue;
		}
		int ans=1;
		for(int k=19;k>=0;k--){
			pii tmp=qry(k,x,y-1);
			if(tmp!=mp(1,n+1)){
				x=tmp.F;
				y=tmp.S;
				ans+=(1<<k);
			}
		}
		if(ans==(1<<20)) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}