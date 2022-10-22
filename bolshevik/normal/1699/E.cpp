#include<cstdio>
#include<iostream>
using namespace std;
const int o=5e6+10;
int T,n,m,a,l,r,cnt,ans;long long f[o];bool vis[o];
inline void ins(int x){
	for(int i=1,j=x;j<=m;++i,j+=x) cnt-=(vis[j]&&!f[j]),f[j]+=f[i],cnt+=(vis[j]&&!f[j]);
}
inline void del(int x){
	if(x==1){cnt+=vis[1];return;}
	for(int i=m/x,j=i*x;i;--i,j-=x) cnt-=(vis[j]&&!f[j]),f[j]-=f[i],cnt+=(vis[j]&&!f[j]);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),cnt=0){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i) vis[i]=f[i]=0;
		for(int a;n--;vis[a]=1) scanf("%d",&a);
		f[1]=1;
		for(int i=2;i<=m;++i) cnt+=vis[i];
		for(l=r=1;cnt;ins(++r));
		for(ans=r-(l++);l<=m;ans=min(ans,r-(l++))){
			for(del(l-1);r<m&&cnt;ins(++r));
			if(cnt) break;
		}
	}
	return 0;
}