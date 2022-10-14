#include<bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)

inline bool up(int&x,const int y){
	return x<y?x=y,1:0;
}
inline bool down(int&x,const int y){
	return x>y?x=y,1:0;
}
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x*f;
}
#define N 1000005
int pri[N],cnt,f[N]; 
inline void init(int n){
	rep(i,2,n){
		if(!f[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
			f[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
//	rep(i,1,20) std::cerr<<pri[i]<<" \n"[i==20];
}
signed main(){
	std::ios::sync_with_stdio(0);
	init(1e6); int T=read();
	while(T--){
		int n=read();
		int l=1,r=cnt,now=0;
		while(l<=r){
			int mid=l+r>>1;
			if(pri[mid]*pri[mid]>n) r=mid-1,now=mid;
			else l=mid+1;
		}
		l=1,r=cnt; int ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(pri[mid]<=n) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%lld\n",ans-now+2);
	}
	return 0;
}