#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef unsigned long long u64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=(1<<20)+5,M=55;
double C[M][M],ans;
char s[M][M];
u64 f[N];
int n,m;

int main(){
	read(n);
	rep(i,1,n){
		scanf("%s",s[i]);
	}
	m=strlen(s[1]);
	rep(i,1,n){
		rep(j,1,n){
			if(i==j) continue;
			int st=0;
			REP(k,m) if(s[i][k]==s[j][k]){
				st|=1<<k;
			}
			f[st]|=u64(1)<<i;
		}
	}
	C[0][0]=1;
	rep(i,1,m){
		C[i][0]=1;
		rep(j,1,m){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	REP(k,m) REP(s,1<<m){
		if(s>>k&1) f[s^(1<<k)]|=f[s];
	}
	REP(s,1<<m){
		ans+=__builtin_popcountll(f[s])/C[m][__builtin_popcount(s)];
	}
	ans/=n;
	printf("%.10lf\n",ans);
	return 0;
}