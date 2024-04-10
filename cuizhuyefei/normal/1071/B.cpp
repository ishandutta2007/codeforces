#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2333;
int n,k;vector<Pii> q[N*N];
char S[N][N],res[N*10];int d[N][N],sz;
int dx[]={1,0};
int dy[]={0,1};
Pii s[N<<1];
vector<Pii> pos[27];int len;
int main() {
	read(n);read(k);rep(i,1,n)scanf("%s",S[i]+1);
	memset(d,-1,sizeof(d));
	d[1][1]=k-(S[1][1]!='a');if(d[1][1]>=0)q[d[1][1]].pb(Pii(1,1));
	per(i,k,0){
		rep(j,0,SZ(q[i])-1){
			int x=q[i][j].fi,y=q[i][j].se;
			rep(k,0,1){
				int nx=x+dx[k],ny=y+dy[k];
				if(nx<=n&&ny<=n&&d[nx][ny]==-1){
					d[nx][ny]=d[x][y]-(S[nx][ny]!='a');
					if(d[nx][ny]>=0)q[d[nx][ny]].pb(Pii(nx,ny));
				}
			}
		}
	}
	int l=0;rep(i,1,n)rep(j,1,n)if(d[i][j]>=0)l=max(l,i+j);
	if(!l)s[++len]=Pii(1,1),res[++sz]=S[1][1];
	else {
		rep(i,1,n)rep(j,1,n)if(d[i][j]>=0&&i+j==l)s[++len]=Pii(i,j);
		rep(i,1,l-1)res[++sz]='a';
	}
	while(s[1].fi+s[1].se<2*n){
		rep(i,0,25)pos[i].clear();
		rep(i,1,len)rep(k,0,1){
			int nx=s[i].fi+dx[k],ny=s[i].se+dy[k];
			if(nx<=n&&ny<=n)pos[S[nx][ny]-'a'].pb(Pii(nx,ny));
		}
		rep(i,0,25)if(SZ(pos[i])){
			len=0;rep(j,0,SZ(pos[i])-1)s[++len]=pos[i][j];
			sort(s+1,s+len+1);len=unique(s+1,s+len+1)-s-1;
			res[++sz]='a'+i;break;
		}
	}
	rep(i,1,sz)printf("%c",res[i]);
	return 0;
}