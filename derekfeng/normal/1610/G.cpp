#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+3;
const int H1=257,M1=998244353,H2=31,M2=1e9+7;
int n,f[300004];
int pos[600008],*lst=pos+N,cur=0,nxt[300004];
char s[300004];
int par[22][300004],dep[300004];
int p1[300004],p2[300004];
int h1[22][300004],h2[22][300004];
void upd(int x,int fa){
	par[0][x]=fa,dep[x]=dep[fa]+1;
	h1[0][x]=s[x],h2[0][x]=s[x];
	for(int i=1;i<20&&par[i-1][x];i++){
		int len=(1<<(i-1)),pa=par[i-1][x];
		par[i][x]=par[i-1][pa];
		h1[i][x]=((ll)h1[i-1][x]*p1[len]+h1[i-1][pa])%M1;
		h2[i][x]=((ll)h2[i-1][x]*p2[len]+h2[i-1][pa])%M2;
	}
}
bool check(int u,int v){
	for(int i=20;~i;i--){
		if(u==n+1)return 1;
		if(v==n+1)return 0;
		if((1<<i)<=min(dep[u],dep[v]))
			if(h1[i][u]==h1[i][v]&&h2[i][u]==h2[i][v])
				u=par[i][u],v=par[i][v];
	}
	return s[u]<s[v];
}
int main(){
	p1[0]=p2[0]=1;
	for(int i=1;i<300004;i++)p1[i]=(ll)p1[i-1]*H1%M1,p2[i]=(ll)p2[i-1]*H2%M2;
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=0;i<600008;i++)pos[i]=-1;
	lst[0]=n+1;
	for(int i=n;i;i--){
		if(s[i]=='(')cur--;
		else cur++;
		nxt[i]=-1;
		if(lst[cur]!=-1){
			int P=lst[cur];
			if(lst[cur-1]==-1||lst[cur-1]>P)nxt[i]=P;
		}
		lst[cur]=i;
	}
	f[n+1]=n+1;
	for(int i=n;i;i--){
		upd(i,f[i+1]);
		if(nxt[i]==-1)f[i]=i;
		else{
			if(check(i,f[nxt[i]]))f[i]=i;
			else f[i]=f[nxt[i]];
		}
	}
	int cur=f[1];
	while(cur<=n){
		putchar(s[cur]);
		cur=par[0][cur];
	}
}