#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int tc,n=120;
ll t,f[122][122];
bool c[122][122];
void qry(ll t){
	memset(f,0,sizeof(f));
	f[0][0]=t;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		ll r=f[i][j]>>1,l=f[i][j]-r;
		f[i+1][j]+=r,f[i][j+1]+=l;
		c[i][j]=f[i][j]&1;
	}
}
pii tran(ll t){
	int x=0,y=0;
	while(t--){
		if(c[x][y])x++;
		else y++;
		if(x>=n||y>=n)break;
	}
	return {x,y};
}
int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%lld",&t);
		ll v=min(t,(ll)n);
		int x,y;scanf("%d%d",&x,&y);
		int d=x+y;
		if(t<d)puts("NO");
		else{
			qry(t-d);
			puts((make_pair(x,y)==tran(d))?"YES":"NO");
		}
	}
}