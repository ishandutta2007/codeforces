#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1<<19,base=19491001,MOD=2147483629,mod=998244353;
int n,m,f[N],ha[N],sz[N],pw[N];
char str[N];
void dfs(int x){
	if(x>m/2){f[x]=sz[x]=1,ha[x]=str[x]&31;return;}
	int ls=x<<1,rs=x<<1|1;
	dfs(ls),dfs(rs),sz[x]=sz[ls]+sz[rs]+1;
	f[x]=1ll*f[ls]*f[rs]%mod;
	if(ha[ls]>ha[rs])swap(ls,rs);
	if(ha[ls]!=ha[rs])f[x]=(f[x]<<1)%mod;
	ha[x]=((str[x]&31)+1ll*ha[ls]*base+1ll*ha[rs]*(pw[sz[ls]+1]))%MOD;
}
int main(){
	n=read(),scanf("%s",str+1);
	m=strlen(str+1);
	pw[0]=1;
	for(int i=1;i<=m;i++)pw[i]=(pw[i-1]<<1)%MOD;
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}