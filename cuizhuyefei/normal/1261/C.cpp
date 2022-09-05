#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e6+11;
vector<int>s[N],qz[N],fg[N],ans[N];int n,m;
#define qz(i,j) (min(i,j)>=0?qz[i][j]:0)
int main() {
	read(n);read(m);
	qz[0].resize(m+3);
	rep(i,1,n){
		char S[N];scanf("%s",S);s[i].pb(0);qz[i].pb(0);
		rep(j,0,m-1)s[i].pb(S[j]=='X'),qz[i].pb(S[j]=='X');
	}
	rep(i,1,n)rep(j,1,m-1)qz[i][j+1]+=qz[i][j];
	rep(i,1,n-1)rep(j,1,m)qz[i+1][j]+=qz[i][j];
	int res=0,L=0,R=min(n,m);
	while(L<=R){
		int mid=(L+R)>>1;
		rep(i,0,n+2)fg[i].clear(),fg[i].resize(m+2);
	//	cerr<<"OwO "<<mid<<endl;
		rep(i,mid+1,n-mid)rep(j,mid+1,m-mid){
		//	cerr<<i<<' '<<j<<endl;
			if(qz[i+mid][j+mid]-qz(i-mid-1,j+mid)-qz(i+mid,j-mid-1)+qz(i-mid-1,j-mid-1)==(mid*2+1)*(mid*2+1)){
				fg[i-mid][j-mid]++,fg[i-mid][j+mid+1]--,fg[i+mid+1][j-mid]--,fg[i+mid+1][j+mid+1]++;
			//	if(mid==1)cerr<<i<<' '<<j<<endl;
			}
		}
	//	cerr<<"OwO"<<endl;
		rep(i,1,n)rep(j,1,m-1)fg[i][j+1]+=fg[i][j];
		rep(i,1,n-1)rep(j,1,m)fg[i+1][j]+=fg[i][j];
		bool ok=1;
		rep(i,1,n)rep(j,1,m)if(s[i][j]){
			ok&=fg[i][j]>0;
			
		//	if(mid==1&&!fg[i][j])printf("gg %d %d\n",i,j);
		}
	//	printf("%d - %d\n",mid,ok);
	//	cerr<<"OwO"<<endl;
		if(ok){
			res=mid,L=mid+1;
			rep(i,0,n+1)ans[i].clear(),ans[i].resize(m+1);
		rep(i,mid+1,n-mid)rep(j,mid+1,m-mid)
			if(qz[i+mid][j+mid]-qz(i-mid-1,j+mid)-qz(i+mid,j-mid-1)+qz(i-mid-1,j-mid-1)==(mid*2+1)*(mid*2+1))
				ans[i][j]=1;
			
		}else R=mid-1;
	//	cerr<<"OwO"<<endl;
	}
	printf("%d\n",res);
	rep(i,1,n){rep(j,1,m)printf("%c",ans[i][j]?'X':'.');puts("");}
	return 0;
}