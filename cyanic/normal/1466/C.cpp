#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=1e5+5,M=26;
int f[M][M],pre[M][M],suf[M][M],a[N],n;
char s[N];

void cmin(int &x,int y){
	if(y<x) x=y;
}

void rmain(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n==1){
		puts("0");
		return;
	}
	rep(i,1,n){
		a[i]=s[i]-'a';
	}
	memset(f,0x3f,sizeof f);
	REP(x,26) REP(y,26){
		if(x==y) continue;
		f[x][y]=(a[1]!=x)+(a[2]!=y);
	}
	rep(i,3,n){
		memset(pre,0x3f,sizeof pre);
		memset(suf,0x3f,sizeof suf);
		REP(x,26) REP(y,26){
			if(0<=x-1) cmin(pre[y][x-1],f[x][y]);
			if(x+1<=25) cmin(suf[y][x+1],f[x][y]);
		}
		memset(f,0x3f,sizeof f);
		REP(x,26){
			rep(y,1,25){
				cmin(suf[x][y],suf[x][y-1]);
			}
			per(y,24,0){
				cmin(pre[x][y],pre[x][y+1]);
			}
			REP(y,26) if(x!=y){
				f[x][y]=min(pre[x][y],suf[x][y])+(a[i]!=y);
			}
		}
	}
	int ans=N;
	REP(x,26) REP(y,26){
		ans=min(ans,f[x][y]);
	}
	printf("%d\n",ans);
}

int main(){
	int T; read(T);
	for(;T;T--) rmain();
	return 0;
}