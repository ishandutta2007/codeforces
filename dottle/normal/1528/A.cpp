#include<bits/stdc++.h>
#define _to e[i].to
#define int long long
const int N=500050;
using namespace std;

struct edge{
	int to,nx;
}e[N];int hd[N],S,n,t;
void add(int fr,int to){
	e[++S]=(edge){to,hd[fr]},hd[fr]=S;
} 
int f[2][N],l[N],r[N];
void clr(){for(int i=1;i<=n;i++)hd[i]=0;S=0;}

void dfs(int k,int fa){
	f[0][k]=f[1][k]=0;
	for(int i=hd[k];i;i=e[i].nx)
		if(_to!=fa){
			dfs(_to,k);
			f[0][k]+=max(f[0][_to]+abs(l[_to]-l[k]),f[1][_to]+abs(r[_to]-l[k]));
			f[1][k]+=max(f[0][_to]+abs(l[_to]-r[k]),f[1][_to]+abs(r[_to]-r[k]));
		}
}

main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld%lld",&l[i],&r[i]);
		for(int i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y),add(x,y),add(y,x);
		dfs(1,0);
		printf("%lld\n",max(f[0][1],f[1][1]));
		clr();
	}
}