#include<cstdio>
using namespace std;
const int o=2010;
int T,n,a[o],vec[30][o],s[30];bool vis[2][o];
inline void opt(){for(int i=1;i<=n;++i) printf("%d ",a[i]);putchar('\n');}
void dfs(int tp,int nw){
	if(vis[tp][nw]) return;
	vis[tp][nw]=1;
	if(!tp){for(int i=0;i<30;++i) if((a[nw]>>i)&1) dfs(1,i);}
	else for(int i=0;i<s[nw];++i) dfs(0,vec[nw][i]);
}
inline bool chk(){
	for(int i=1;i<=n;++i) vis[0][i]=0;
	for(int i=0;i<30;++i) vis[1][i]=s[i]=0;
	for(int i=1;i<=n;++i) for(int j=0;j<30;++j) if((a[i]>>j)&1) vec[j][s[j]++]=i;
	dfs(0,1);
	for(int i=1;i<=n;++i) if(!vis[0][i]) return false;
	return true;
}
inline int lowbit(int x){return x&-x;}
inline void slv(){
	int res=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),res+=!a[i],a[i]+=!a[i];
	if(chk()){printf("%d\n",res);opt();return;}
	for(int i=1;i<=n;--a[i++]){
		--a[i];
		if(chk()){printf("%d\n",res+1);opt();return;}
		a[i]+=2;
		if(chk()){printf("%d\n",res+1);opt();return;}
	}
	int lb=0;
	for(int i=1;i<=n;++i) if(lowbit(a[i])>lb) lb=lowbit(a[i]);
	for(int i=1;i<=n;++i) if(lowbit(a[i])==lb){--a[i];break;}
	for(int i=1;i<=n;++i) if(lowbit(a[i])==lb){++a[i];break;}
	printf("%d\n",res+2);opt();
}
int main(){
	for(scanf("%d",&T);T--;slv()) scanf("%d",&n);
	return 0;
}