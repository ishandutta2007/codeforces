#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,int> piii;
#define fi first
#define se second
int T,n,m,N;
piii a[300004];
int ord[200004],pos[200004];
pii z[200004],g[200004];
int cnt,b[200004],t[200004],c[200004];
bool cmp(piii A,piii B){
	return A.fi.fi*B.fi.se>B.fi.fi*A.fi.se;
}
int s[3][200004];
char ans[200004];
void sol(){
	scanf("%d%d",&n,&m),N=cnt=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1),reverse(b+1,b+n+1);
	for(int i=1;i<=m;i++){
		ll S=0;int K;scanf("%d",&K);
		for(int j=1;j<=K;j++){
			scanf("%d",&c[j]);
			S+=c[j];
		}
		a[++N]={{S,K},-i},pos[i]=0;
		for(int j=1;j<=K;j++){
			++cnt,t[cnt]=i;
			a[++N]={{S-c[j],K-1},cnt};
			g[cnt]={S-c[j],K-1};
		}
	}
	sort(a+1,a+N+1,cmp);
	int num=0;
	for(int i=1;i<=N;i++){
		if(a[i].se<0)num++,z[num]=a[i].fi,pos[-a[i].se]=num;
		else{
			if(!pos[t[a[i].se]])ord[a[i].se]=num+1;
			else ord[a[i].se]=num;
		}
	}
	for(int i=1;i<=m;i++){
		s[0][i]=s[0][i-1];
		s[1][i]=s[1][i-1];
		s[2][i]=s[2][i-1];
		if((ll)b[i-1]*z[i].se<z[i].fi)s[0][i]++;
		if((ll)b[i]*z[i].se<z[i].fi)s[1][i]++;
		if((ll)b[i+1]*z[i].se<z[i].fi)s[2][i]++;
	}
	for(int i=1;i<=cnt;i++){
		ans[i]='1';
		int L=ord[i],R=pos[t[i]];
		if(s[1][min(L,R)-1]!=0||s[1][m]-s[1][max(L,R)]!=0){
			ans[i]='0';continue;
		}
		if(L<=R){
			if((ll)b[L]*g[i].se<g[i].fi||s[2][R-1]-s[2][L-1]!=0)ans[i]='0';
		}else{
			if((ll)b[L]*g[i].se<g[i].fi||s[0][L]-s[0][R]!=0)ans[i]='0';
		}
	}
	for(int i=1;i<=cnt;i++)putchar(ans[i]);puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}