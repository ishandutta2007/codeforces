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
const int N = 233333;
int a[N],n,k;ll res;int t[7],used[7];
map<Vi,int>Map;int tot;Vi q[121];
int mtr[121][121],pos[121],s[121],len;
void dfs(int dep){
	if(dep>k){
		Vi c;rep(i,1,k)c.pb(t[i]);Map[c]=++tot;q[tot]=c;
		return;
	}
	rep(i,1,k)if(!used[i]){
		used[i]=1;t[dep]=i;
		dfs(dep+1);
		used[i]=0;
	}
}
inline void ins(int x, int p){
	if(pos[x]<=p)return;pos[x]=p;s[++len]=x;
	static int q[121];int f=0,r=1;q[f]=x;
	rep(i,1,tot)if(pos[i]<=p){
		if(pos[mtr[x][i]]>p)pos[mtr[x][i]]=p,q[r++]=mtr[x][i];
		if(pos[mtr[i][x]]>p)pos[mtr[i][x]]=p,q[r++]=mtr[i][x];
	}
	while(f!=r){
		int i=q[f++];
		rep(c,1,len){
			int x=s[c];
			if(pos[mtr[x][i]]>p)pos[mtr[x][i]]=p,q[r++]=mtr[x][i];
			if(pos[mtr[i][x]]>p)pos[mtr[i][x]]=p,q[r++]=mtr[i][x];
		}
	}
	/*rep(i,1,tot)rep(j,1,tot)if(pos[i]<=p&&pos[j]<=p){
		if(!(pos[mtr[i][j]]<=p))
			cerr<<x<<' '<<i<<' '<<j<<' '<<pos[i]<<' '<<pos[j]<<' '<<p<<endl;
		assert(pos[mtr[i][j]]<=p);
	}*/
}
int main() {
	read(n);read(k);
	dfs(1);
	rep(x,1,tot)rep(y,1,tot){
		Vi z;rep(i,0,k-1)z.pb(q[y][q[x][i]-1]);
		mtr[x][y]=Map[z];assert(Map[z]>0);
	}
	rep(i,1,n){
		Vi s;rep(j,1,k){int x;read(x);s.pb(x);}
		a[i]=Map[s];
	}
	per(i,n,1){
		vector<Pii> c;rep(j,1,len)c.pb(Pii(s[j],pos[s[j]]));len=0;
		rep(j,1,tot)pos[j]=n+1;
		ins(a[i],i);
		rep(j,0,SZ(c)-1)ins(c[j].fi,c[j].se);
	//	rep(j,1,tot)if(pos[j]<=n)cerr<<j<<' ';
	//	cerr<<i<<":";rep(j,1,len)cerr<<pos[s[j]]<<' ';cerr<<endl;
		rep(j,1,tot)res+=n-pos[j]+1;
	}
	cout<<res;
	return 0;
}