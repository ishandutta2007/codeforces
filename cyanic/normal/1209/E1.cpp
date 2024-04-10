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

const int N=15,M=(1<<12)+5;
int f[N][M],g[M],a[N][M],b[N],mark[M],cur[N];
int n,m,cnt,cc;
pii x[N*M];

inline void cmax(int &x,const int y){
	x=(y>x?y:x);
}

void rmain(){
	memset(mark,0,sizeof mark);
	read(n),read(m),cc=0;
	rep(i,1,n)rep(j,1,m){
		read(a[i][j]);
		x[++cc]=mp(a[i][j],j);
	}
	sort(x+1,x+cc+1,greater<pii>());
	cnt=0;
	rep(i,1,cc)
		if(!mark[x[i].se]){
			mark[x[i].se]=1;
			cur[++cnt]=x[i].se;
			if(cnt==n)break;
		}
	memset(f[0],0xc0,sizeof f[0]);
	f[0][0]=0;
	rep(i,1,cnt){
		memset(f[i],0xc0,sizeof f[i]);
		rep(j,1,n){
			int pos=j;
			rep(k,1,n){
				b[k-1]=a[pos][cur[i]];
				pos++;
				if(pos==n+1)pos=1;
			}
			REP(s,1<<n)g[s]=f[i-1][s];
			for(int k=0,d=1;k<n;k++,d<<=1)
				for(int i=0;i<(1<<n);i+=d<<1){
					int *l=g+i,*r=g+i+d;
					for(int j=0;j<d;j++,l++,r++)
						cmax(*r,(*l)+b[k]);
				}
			REP(s,1<<n)cmax(f[i][s],g[s]);
		}
	}
	printf("%d\n",f[cnt][(1<<n)-1]);
}

int main(){
	int T;
	read(T);
	while(T--)rmain();

	return 0;
}