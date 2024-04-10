#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<vector<int>,int> mp;
ll f[1<<18|5][25],g[25][1<<18|5],h[23][1<<18|5],ans[10005],ans2[1<<18|5];
int a[25][25],len[1<<18|5];
inline bool gbit(int sta,int i){ return (sta>>i-1)&1; }
inline int ubit(int i){ return 1<<i-1; }
int to_length_type(int sta,int n){
	vector<int> ret; ret.push_back(1);
	for(int i=1;i<n;++i)
		if(gbit(sta,i))
			ret[(int)ret.size()-1]++;
		else
			ret.push_back(1);
	sort(ret.begin(),ret.end());
//	for(auto x:ret) printf("[%d]",x); puts("");
	return mp[ret];
}
void read(int n){
	static char s[25];
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=n;++j)
			a[i][j]=s[j]-'0';
	}
}
void FWT(ll a[],int n){
	for(int s=1;s<n;s<<=1)
		for(int i=0;i<n;++i)
			if(i&s) a[i]+=a[i-s];
}
void DFWT(ll a[],int n){
	for(int s=1;s<n;s<<=1)
		for(int i=0;i<n;++i)
			if(i&s) a[i]-=a[i-s];
}
void dfs(int pos,int last,int sum,int n,vector<int> id){
	int tp=(int)id.size();
//	printf("{%d}",pos);
//	for(int sta=0;sta<1<<n;++sta) printf("/%lld/",h[tp][sta]); puts("");
	if(sum==n){
		for(int sta=0;sta<1<<n;++sta)
			if((n-len[sta])&1) ans[pos]-=h[tp][sta];
			else ans[pos]+=h[tp][sta];
		return;
	}
	for(int i=last;sum+i<=n;++i){
		id.push_back(i);
		int t=mp[id]=(int)mp.size();
		for(int sta=0;sta<1<<n;++sta)
			h[tp+1][sta]=h[tp][sta]*g[i][sta];
//		printf("<%d %d>",pos,t);
		dfs(t,i,sum+i,n,id);
		id.pop_back();
	}
}
int main(){
	int n; scanf("%d",&n);
	read(n); len[0]=0;
	for(int sta=1;sta<1<<n;++sta)
		len[sta]=len[sta-(sta&-sta)]+1;
	for(int i=1;i<=n;++i) f[1<<i-1][i]=1;
	for(int sta=1;sta<1<<n;++sta){
		if((sta&-sta)==sta) continue;
		for(int i=1;i<=n;++i)
			if(gbit(sta,i)){
				for(int j=1;j<=n;++j)
					if(gbit(sta,j)&&j!=i&&a[j][i])
						f[sta][i]+=f[sta-ubit(i)][j];
//				printf("<%d %d %lld>",sta,i,f[sta][i]);
			}
	}
	for(int sta=0;sta<1<<n;++sta){
		g[len[sta]][sta]=0;
		for(int i=1;i<=n;++i)
			if(gbit(sta,i))
				g[len[sta]][sta]+=f[sta][i];
	}
	for(int i=1;i<=n;++i)
		FWT(g[i],1<<n);
//	puts("");
//	for(int sta=0;sta<1<<n;++sta) printf("(%lld)",g[sta]);
	int t=mp[vector<int>({})]=(int)mp.size();
	h[0][0]=1; FWT(h[0],1<<n);
	dfs(t,1,0,n,vector<int>({}));
/*	for(auto x:mp){
		for(auto y:x.first) printf("[%d]",y);
		printf("<%lld>\n",ans[x.second]);
	}
*/	for(int sta=0;sta<1<<n-1;++sta){
		ans2[sta]=ans[to_length_type(sta,n)];
		if(len[sta]&1) ans2[sta]=-ans2[sta];
//		printf("{%lld}",ans2[sta]);
	}
//	cerr<<mp.size();
	reverse(ans2,ans2+(1<<n-1));
	FWT(ans2,1<<n);
	reverse(ans2,ans2+(1<<n-1));
	for(int sta=0;sta<1<<n-1;++sta)
		printf("%lld ",abs(ans2[sta]));
	return 0;
}