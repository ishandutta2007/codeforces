#include<cstdio>
#include<algorithm>
using namespace std;
int T,k,c[110],p,t;bool flg,vis[50];long long sm,f[50],S;
inline bool chk(){
	for(int i=1;i<=p;++i) vis[i]=0;
	for(int i=1,v;i<=k;++i){
		v=c[i];
		for(int j=p,ban=0;j;--j,ban=max(ban-1,0))
			if(v>=f[j]&&!vis[j]&&!ban&&(j>1||i!=t)) vis[j]=1,v-=f[j],ban=2;
		if(v) return false;
	}
	return true;
}
int main(){
	f[0]=f[1]=1;
	for(int i=2;i<50;++i) f[i]=f[i-1]+f[i-2];
	for(scanf("%d",&T);T--;sm=S=0){
		scanf("%d",&k);
		for(int i=1;i<=k;++i) scanf("%d",&c[i]),sm+=c[i];
		sort(c+1,c+k+1);
		for(p=0,S=1;f[p+1]<=c[k]&&S+f[p+1]<=sm;S+=f[++p]);
		if(S^sm){printf("NO\n");continue;}
		flg=0;
		for(int i=1;i<=k&&!flg;++i) --c[t=i],flg=chk(),++c[i];
		printf(flg?"YES\n":"NO\n");
	}
	return 0;
}