#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
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

const int N=505;
const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
int mark[N][N],n,m,K,sum,cnt,x,y;
char s[N][N];

void dfs(int x,int y){
	if(cnt==sum-K) return;
	mark[x][y]=++cnt;
	REP(k,4){
		int xx=x+dx[k],yy=y+dy[k];
		if(s[xx][yy]=='.'&&!mark[xx][yy]) dfs(xx,yy);
	}
}

int main(){
	read(n),read(m),read(K);
	rep(i,1,n){
		scanf("%s",s[i]+1);
		rep(j,1,m) if(s[i][j]=='.'){
			x=i,y=j,sum++;
		}
	}
	dfs(x,y);
	rep(i,1,n){
		rep(j,1,m){
			if(s[i][j]=='.'&&!mark[i][j]) putchar('X');
			else putchar(s[i][j]);
		}
		puts("");
	}
	return 0;
}