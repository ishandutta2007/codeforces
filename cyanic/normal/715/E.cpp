#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=255,mod=998244353;
int f[N],g[N],p[N],q[N],cur[N],rev[N],vis[N],L[N],R[N],owo[N];
int n,bas,ans,c0,c1,c2,c3;

int mul(int x,int y){
	return (ll)x*y%mod;
}
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	read(n);
	rep(i,1,n) read(p[i]);
	rep(i,1,n) read(q[i]);
	rep(i,1,n){
		if(p[i]&&q[i]) cur[p[i]]=q[i],rev[q[i]]=p[i];
		else if(q[i]) L[q[i]]=1;
		else if(p[i]) R[p[i]]=1;
		else c0++;
		owo[p[i]]=owo[q[i]]=1;
	}
	rep(i,1,n){
		if(vis[i]||rev[i]) continue;
		int p=i; vis[p]=1;
		while(cur[p]) p=cur[p],vis[p]=1;
		if(L[i]&&R[p]) c0++;
		else if(R[p]) c1++;
		else if(L[i]) c2++;
		else if(owo[i]) c3++;
	}
	rep(i,1,n){
		if(vis[i]) continue;
		int p=i; bas++;
		while(cur[p]!=i) vis[p]=1,p=cur[p];
		vis[p]=1;
	}
	int res=1,cnt=0;
	rep(i,1,n) if(!owo[i]) res=mul(res,++cnt);
	rep(i,1,c3) res=mul(res,c0+1-i);
	f[0]=res;
	rep(i,1,c0+c1){
		memset(g,0,sizeof g);
		rep(j,0,i){
			add(g[j+1],f[j]);
			add(g[j],mul(f[j],i-1));
		}
		memcpy(f,g,sizeof g);
	}
	rep(i,1,c2){
		memset(g,0,sizeof g);
		rep(j,0,c0+c1+i){
			add(g[j+1],f[j]);
			add(g[j],mul(f[j],i-1+c0));
		}
		memcpy(f,g,sizeof g);
	}
	per(i,n,1) printf("%d ",i<bas?0:f[i-bas]);
	return 0;
}