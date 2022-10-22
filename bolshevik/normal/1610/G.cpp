#include<cstdio>
#include<cstring>
using namespace std;
const int o=3e5+10,MOD=1e9+7;
int n,st[o],tp,nxt[o],p[o][20],hsh[o][20],z[o],pw[o];char s[o];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=pw[0]=1;i<=n;++i) pw[i]=pw[i-1]*114514ll%MOD;
	for(int i=1;i<=n;++i)
		if(s[i]=='(') st[++tp]=i;
		else if(tp) nxt[st[tp--]]=i+1;
	p[n+1][0]=z[n+1]=n+1;
	for(int i=n,u,v;i;--i){
		p[z[i]=i][0]=z[i+1];hsh[i][0]=s[i];
		for(int j=1;j<20;++j)
			p[i][j]=p[p[i][j-1]][j-1],hsh[i][j]=(hsh[i][j-1]+hsh[p[i][j-1]][j-1]*1ll*pw[1<<(j-1)])%MOD;
		if(!nxt[i]) continue;
		u=i;v=z[nxt[i]];
		for(int j=19;j+1;--j) if(hsh[u][j]==hsh[v][j]) u=p[u][j],v=p[v][j];
		if(v>n||s[u]>s[v]) z[i]=z[nxt[i]];
	}
	for(int i=z[1];i<=n;i=p[i][0]) putchar(s[i]);
	return 0;
}