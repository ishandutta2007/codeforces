#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<cassert>
#define SZ(x) ((int)x.size())
#define pb push_back
#define fi first
#define se second
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
const int N = 203000, M = 450;
int n,a[N],b[N],mrk[N],prime[N],len,s[N],qz[N][26];
void getp(int n){
	rep(i,2,n){
		if(!mrk[i])prime[++len]=i;
		rep(j,1,len){
			if(i*prime[j]>n)break;
			mrk[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
struct zkw{
	int a[N<<2],m;
	void init(){
		for(m=1;m<=n+1;m<<=1);
		rep(i,1,m*2)a[i]=n+1;
	}
	void modify(int l, int r, int x){
		l=l+m-1;r=r+m+1;
		while((l>>1)!=(r>>1)){
			if(!(l&1))a[l+1]=min(a[l+1],x);
			if(r&1)a[r-1]=min(a[r-1],x);l>>=1;r>>=1;
		}
	}
	inline void umin(int &x,int y){x=x<y?x:y;}
	inline void getlen(int *b){
		rep(i,1,m)umin(a[i<<1],a[i]),umin(a[i<<1|1],a[i]);
		rep(i,1,n)b[i]=a[m+i];
	}
}yzr1,yzr2;
struct SA{
	int buc[N],sa[N],rk[N],tt[N],h[N],v[N][19],Log[N];
	void init(char *a){
		rep(i,1,n){Log[i]=Log[i-1];if(i==(1<<Log[i]+1))Log[i]++;}
		memset(buc,0,4*(n+2));
		rep(i,1,n)buc[a[i]]++;
		rep(i,1,256)buc[i]+=buc[i-1];
		rep(i,1,n)sa[buc[a[i]]--]=i;
		rep(i,1,n)rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
		for(int j=1;j<n;j<<=1){
			int p=0;rep(i,n-j+1,n)tt[++p]=i;
			rep(i,1,n)if(sa[i]-j>=1)tt[++p]=sa[i]-j;
			memset(buc,0,4*(n+2));
			rep(i,1,n)buc[rk[i]]++;
			rep(i,1,n)buc[i]+=buc[i-1];
			per(i,n,1)sa[buc[rk[tt[i]]]--]=tt[i];
			rep(i,1,n)tt[sa[i]]=tt[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||(sa[i]+j<=n?rk[sa[i]+j]:-1)!=(sa[i-1]+j<=n?rk[sa[i-1]+j]:-1));
			memcpy(rk,tt,4*(n+2));
		}
		int p=0;
		rep(i,1,n){
			if(p)p--;int j=sa[rk[i]-1];
			while(i+p<=n&&j+p<=n&&a[i+p]==a[j+p])p++;
			h[rk[i]]=p;
		}
		rep(i,1,n)v[i][0]=h[i];
		rep(j,1,18)rep(i,1,n-(1<<j)+1)v[i][j]=min(v[i][j-1],v[i+(1<<j-1)][j-1]);
	}
	inline int lcp(int i, int j){
		i=rk[i];j=rk[j];if(i>j)swap(i,j);i++;
		int k=Log[j-i+1];return min(v[i][k],v[j-(1<<k)+1][k]);
	}
}x,y;
inline int lcp(int i, int j){
	return x.lcp(i,j);
}
inline int lcs(int i, int j){
	return y.lcp(n-i+1,n-j+1);
}
inline void ins(int l, int r, int x){//addedge
//	printf("ins %d %d %d\n",l,r,x);
	yzr1.modify(l,r,x);yzr2.modify(l+x-1,r+x-1,x);
}
int v[N][18],Log[N];
void init(int *a){
	rep(i,1,n)v[i][0]=a[i];
	rep(j,1,17)rep(i,1,n-(1<<j)+1)v[i][j]=min(v[i][j-1],v[i+(1<<j-1)][j-1]);
	rep(i,1,n){Log[i]=Log[i-1];if(i==(1<<Log[i]+1))Log[i]++;}
}
inline int querymin(int l, int r){
	int k=Log[r-l+1];return min(v[l][k],v[r-(1<<k)+1][k]);
}
inline int solve(int l, int r){
	bool vis[26]={0};bool cf=0;
	rep(i,l,r)if(vis[s[i]]){cf=1;break;}else vis[s[i]]=1;
	if(!cf)return -1;
	int len=r-l+1;
	while(mrk[len]){
		int x=mrk[len];
		if(lcp(l,l+(r-l+1)/x)>=r-(l+(r-l+1)/x)+1)return 1;
		len/=mrk[len];
	}
	if(len>1&&lcp(l,l+(r-l+1)/len)>=r-(l+(r-l+1)/len)+1)return 1;
	if(qz[r][s[l]]-qz[l][s[l]]==0&&qz[r-1][s[r]]-qz[l-1][s[r]]==0){
		if(querymin(l,r)>r)return 4;
	}
	if(a[l]<=r)return 2;
	if(b[r]>=l)return 2;
	rep(i,1,min(M,(r-l+1)>>1))if(lcp(l,r-i+1)>=i)return 2;
	/*rep(i,max(1,x.rk[l]-M),min(n,x.rk[l]+M))if(x.sa[i]>=l&&x.sa[i]<=r&&x.sa[i]!=l)
		if(lcp(l,x.sa[i])>=r-x.sa[i]+1)return 2;*/
	int mid=(l+r+2)/2;
	per(i,x.rk[l],max(1,x.rk[l]-M))if(x.sa[i]>=mid&&x.sa[i]<=r&&x.sa[i]!=l)
		if(lcp(l,x.sa[i])>=r-x.sa[i]+1)return 2;
	rep(i,x.rk[l],min(n,x.rk[l]+M))if(x.sa[i]>=mid&&x.sa[i]<=r&&x.sa[i]!=l)
		if(lcp(l,x.sa[i])>=r-x.sa[i]+1)return 2;
	return 3;
}
void init0(){
	yzr1.getlen(a),yzr2.getlen(b);
//	rep(i,1,n)printf("%d:%d %d\n",i,a[i],b[i]);
	rep(i,1,n)a[i]=i+a[i]-1,b[i]=i-b[i]+1;
	rep(i,1,n){
		memcpy(qz[i],qz[i-1],sizeof(qz[i]));qz[i][s[i]]++;
	}
	init(a);
}
int main() {//freopen("1.in","r",stdin);
		getp(N-1);
		static char a[N];read(n);scanf("%s",a+1);
		static char A[N];rep(i,1,n)A[n-i+1]=a[i];
		rep(i,1,n)s[i]=a[i]-'a';
		x.init(a);y.init(A);yzr1.init();yzr2.init();
		rep(k,1,n/2){
			for(int i=k;i+k<=n;i+=k){
				int l=i-lcs(i,i+k)+1,r=i+lcp(i,i+k)-1;r=r-k+1;
				l=max(l,i-k+1);r=min(r,i);
				if(l<=r)ins(l,r,2*k);
			}
		}
	init0();
	int q;read(q);
	while(q--){
		int l,r;read(l);read(r);printf("%d\n",solve(l,r));
	}
	return 0;
}