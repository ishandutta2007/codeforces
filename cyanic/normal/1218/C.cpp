#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=505;
const ll inf=1e18;
vector<pii>v[N][N][2];
ll f[2][N][N][2],tt[N][2],sum;
int n,m,K,x,y,d,t,e;

int chk(int x,int y,int t){
	return t<=x+y&&(x+y-t)%4==0;
}

void ins(int x,int y,int a,int b){
	v[x][y][0].pb(mp(a,e));
	v[x][y][1].pb(mp(b,e));
}

void upd(ll &x,ll y){
	if(y<x)x=y;
}

int main(){
	read(n),read(m),read(K);
	rep(i,1,K){
		read(x),read(y),read(d),read(t),read(e);
		int A=chk(x,y,t);
		int B=chk(x+d,y-d,t+1);
		int C=chk(x+d,y,t+2);
		int D=chk(x,y+d,t+3);
		//printf("# %d %d %d %d !\n",A,B,C,D);
		if(A)ins(x,y,n,m);
		if(B)ins(x+d,y-d,n,m);
		if(C)ins(x+d,y,(A?d-1:n),(B?d-1:m));
		if(D)ins(x,y+d,n,(A?d-1:m));
	}
	int cur=0,nxt=1;
	memset(f[cur],0x3f,sizeof f[cur]);
	f[cur][0][0][0]=0;
	rep(s,0,n+m-2){
		int up=max(0,s-(m-1));
		int down=min(s,n-1);
		rep(x,up,down){
			int y=s-x;
			memset(tt,0,sizeof tt);
			for(auto o:v[x][y][0])
				tt[o.fi][0]+=o.se;
			for(auto o:v[x][y][1])
				tt[o.fi][1]+=o.se;
			sum=0;
			per(i,n,0){
				sum+=tt[i][0];
				f[cur][x][i][0]+=sum;
			}
			sum=0;
			per(i,m,0){
				sum+=tt[i][1];
				f[cur][x][i][1]+=sum;
			}
		}
		memset(f[nxt],0x3f,sizeof f[nxt]);
		rep(x,up,down){
			int y=s-x;
			rep(keep,0,max(n,m)){
				ll tmp=f[cur][x][keep][0];
				if(tmp<inf){
					//printf("# %d %d %d %d   %lld\n",x,y,keep,0,tmp);
					if(y<m-1)upd(f[nxt][x][1][1],tmp);
					if(x<n-1)upd(f[nxt][x+1][keep+1][0],tmp);
				}
				tmp=f[cur][x][keep][1];
				if(tmp<inf){
					//printf("# %d %d %d %d   %lld\n",x,y,keep,1,tmp);
					if(y<m-1)upd(f[nxt][x][keep+1][1],tmp);
					if(x<n-1)upd(f[nxt][x+1][1][0],tmp);
				}
			}
		}
		swap(cur,nxt);
	}
	ll ans=inf;
	rep(i,0,n)upd(ans,f[nxt][n-1][i][0]);
	rep(i,0,m)upd(ans,f[nxt][n-1][i][1]);
	cout<<ans<<endl;
	return 0;
}