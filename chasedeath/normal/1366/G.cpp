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

const int N=10010,P=1e9+7;

int n,m;
char s[N],t[N];
int dp[N][N];

int main(){
	scanf("%s%s",s,t),n=strlen(s),m=strlen(t);
	rep(i,0,n) memset(dp[i],63,(min(m,i)+2)<<2);
	rep(i,*dp[0]=0,n-1) {
		if(s[i]!='.') {
			int j=i,c=0;
			do c+=s[j++]=='.'?-1:1;
			while(c && j<n);
			if(!c) rep(k,0,min(m,i)) cmin(dp[j][k],dp[i][k]);
		}
		rep(j,0,min(m,i)) {
			cmin(dp[i+1][j],dp[i][j]+1);
			if(s[i]==t[j]) cmin(dp[i+1][j+1],dp[i][j]);
		}
	}
	printf("%d\n",dp[n][m]);
}