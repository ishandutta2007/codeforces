#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=250,P=998244353;

int n,m;
char s[N];
int nxt[N][26],cnt,End[N];
string str[N];

int mk[N];
int stx[N],sty[N],stcnt;
int id[N][N];
struct Mat{
	int a[N][N];
	void clear(){ rep(i,1,stcnt) rep(j,1,stcnt) a[i][j]=0; }
	Mat operator * (const Mat x) const {
		Mat res; res.clear();
		rep(i,1,stcnt) rep(j,1,stcnt) if(a[i][j]) rep(k,1,stcnt) res.a[i][k]=(res.a[i][k]+1ll*a[i][j]*x.a[j][k])%P;
		return res;
	}
} x;

Mat qpow(Mat x,int k){
	Mat res=x;
	for(k--;k;k>>=1,x=x*x) if(k&1) res=res*x;
	return res;
}

int main(){
	n=rd(),m=rd();
	rep(i,1,n) {
		scanf("%s",s+1);
		int u=0;
		for(int j=1;s[j];++j) {
			int &v=nxt[u][s[j]-'a'];
			if(!v) v=++cnt,str[v]=str[u]+s[j];
			u=v;
		}
		End[u]=1;
	}
	rep(i,0,cnt) rep(j,0,25) mk[i]|=nxt[i][j];
	rep(u,0,cnt) {
		rep(j,0,str[u].size()) {
			int v=0;
			rep(k,j,str[u].size()-1) {
				v=nxt[v][str[u][k]-'a'];
				if(!v) {
					v=-1;
					break;
				}
			}
			if(~v && mk[u] && mk[v]) {
				//cout<<"new state "<<u<<' '<<v<<' '<<str[u]<<' '<<str[v]<<endl;
				stx[++stcnt]=u,sty[stcnt]=v;
				id[u][v]=stcnt;
			}
		}
	}
	rep(i,1,stcnt) {
		rep(k,0,25) if(nxt[stx[i]][k] && nxt[sty[i]][k]) {
			int a=nxt[stx[i]][k],b=nxt[sty[i]][k];
			rep(x,1-End[a],1) rep(y,1-End[b],1) {
				int u=a*x,v=y*b;
				if(str[u].size()<str[v].size()) swap(u,v);
				if(!id[u][v]) continue;
				//assert(id[u][v]);
				//cout<<"$"<<i<<' '<<k<<' '<<id[u][v]<<endl;
				::x.a[i][id[u][v]]++;
			}
		}
	}
	/*rep(i,1,m) {
		Mat t=qpow(x,m);
		rep(j,1,stcnt) cout<<t.a[1][j]<<' ';
		puts("");
	}*/
	printf("%d\n",qpow(x,m).a[1][1]);
}