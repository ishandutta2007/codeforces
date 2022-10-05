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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=20,mod=998244353;
int f[N][N][N][N][2][2];
int g[N][N][N][N][2][2];
int x[N],y[N],n,m;

void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int main(){
	read(n),read(m);
	rep(i,1,n) read(x[i]),read(y[i]);
	f[0][0][0][0][0][0]=1;
	for(;m;m>>=1){
		memset(g,0,sizeof g);
		REP(px,N) REP(nx,N)
			REP(py,N) REP(ny,N)
				REP(fx,2) REP(fy,2){
					int t=f[px][nx][py][ny][fx][fy];
					if(!t) continue;
					REP(s,1<<n){
						int Px=px,Nx=nx,Py=py,Ny=ny;
						rep(i,1,n) if(s>>(i-1)&1){
							Px+=max(x[i],0);
							Nx-=min(x[i],0);
							Py+=max(y[i],0);
							Ny-=min(y[i],0);
						}
						if((Px&1)!=(Nx&1)||(Py&1)!=(Ny&1)) continue;
						int gx=((Px&1)<(m&1)?0:((Px&1)>(m&1)?1:fx));
						int gy=((Py&1)<(m&1)?0:((Py&1)>(m&1)?1:fy));
						Px>>=1,Nx>>=1,Py>>=1,Ny>>=1;
						add(g[Px][Nx][Py][Ny][gx][gy],t);
					}
				}
		swap(f,g);
	}
	cout<<((f[0][0][0][0][0][0]+mod-1)%mod)<<endl;
	return 0;
}