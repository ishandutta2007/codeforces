#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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

char BUF[1 << 22], *ST, *EN;
#define gc (ST == EN && (ST = BUF, EN = BUF + fread(BUF, 1, 1 << 21, stdin), ST == EN) ? EOF : *ST++)

template<class T> void read(T &x){
	int f=0; x=0; char ch=gc;
	for(;!isdigit(ch);ch=gc) f|=(ch=='-');
	for(;isdigit(ch);ch=gc) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=65;
const int mod=1e9+7;
int a[N],f[N][9],mx;
ll m;

inline const void add(int &x,const int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

void rmain(){
	read(m);
	REP(i,60){
		a[i]=(m>>i&1);
		if(a[i]) mx=i;
	}
	memset(f,0,sizeof f);
	f[mx+1][0]=1;
	per(i,mx,0){
		rep(j,0,8){
			if(!f[i+1][j]) continue;
			int now=j*2+a[i];
			add(f[i][now-min(now,7)],f[i+1][j]);
			if(now<8){
				add(f[i][now+1],mod-f[i+1][j]);
			}
		}
		rep(j,1,8) if(f[i][j-1]){
			add(f[i][j],f[i][j-1]);
		}
	}
	printf("%d\n",f[0][0]);
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}