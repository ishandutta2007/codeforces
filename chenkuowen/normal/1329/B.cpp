#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){ 
	for(auto t:y) t<x?x=t:0;
}
template<class T> inline void dmax(T& x,vector<T> y){
	for(auto t:y) t>x?x=t:0;
}
int f[35][35],g[35];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int d,m,ans=0; scanf("%d%d",&d,&m);
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int i=0;1<<i<=d;++i)
			if(1<<i+1>d) g[i]=(d-(1<<i)+1)%m;
			else g[i]=(1<<i)%m;
	//	for(int i=0;1<<i<=d;++i) printf("[%d]",g[i]); puts("");
		for(int i=0;1<<i<=d;++i) f[0][i]=g[i],ans=(ans+f[0][i])%m;
		for(int i=1;i<=30;++i)
			for(int j=0;1<<j<=d;++j){
				for(int k=0;k<j;++k)
					f[i][j]=(f[i][j]+1ll*f[i-1][k]*g[j])%m;
				ans=(ans+f[i][j])%m;
			}
		printf("%d\n",ans);
	}
	return 0;
}