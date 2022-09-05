#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 202;
char s[N][N],l[N][15],r[N][15];
int n,m,ans[N];
ll len[N];
bool used[N][15][1<<14]; //1..14

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() { //freopen("data.out","r",stdin); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	memset(l,'0',sizeof(l)); memset(r,'0',sizeof(r)); //init
	read(n); rep(i,1,n) {
		scanf("%s",s[i]+1); len[i]=strlen(s[i]+1);
		rep(j,1,min(14,len[i])) l[i][j]=s[i][j];
		int x=0; per(j,len[i],max(1,len[i]-13)) r[i][++x]=s[i][j];
		//getused!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		rep(j,1,len[i]) rep(k,j,min(j+13,len[i])) {
			int x=0;
			rep(p,j,k) x=2*x+s[i][p]-'0';
			used[i][k-j+1][x]=1;
		}
	//	printf("%d %d %d\n",l[i][1],r[i][1],len[i]);
	}
	read(m);
	rep(p,1,m) {
		int a,b; read(a); read(b);
		if (len[a]>100||len[b]>100) len[n+p]=100; else len[n+p]=len[a]+len[b];
		rep(j,1,min(14,len[n+p])) 
			if (j<=len[a]) l[n+p][j]=l[a][j];
			else l[n+p][j]=l[b][j-len[a]];
		int x=0; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		rep(j,1,min(14,len[n+p])) {
			if (j<=len[b]) r[n+p][++x]=r[b][j];
			else r[n+p][++x]=r[a][j-len[b]];
		//	if (p==1&&x==1) printf("<< %c >> \n",r[n+p][x]);
		}
		//zhongjian
		rep(i,1,min(14,len[a])) rep(j,1,min(14,len[b])) if (i+j<=14) {
			int x=0;
			per(k,i,1) x=x*2+r[a][k]-'0';
			rep(k,1,j) x=x*2+l[b][k]-'0';
			used[n+p][i+j][x]=1;
		//	if (i+j==2) printf("<%d %d %d %d %d>",x,used[n+p][2][0],used[n+p][2][1],used[n+p][2][2],used[n+p][2][3]);
		}
	//	printf("%d %d\n",l[n+p][1],r[n+p][1]);
		int ans=14;
		per(i,14,1) {
			bool flag=1;
			rep(j,0,(1<<i)-1) {
				used[n+p][i][j]|=used[a][i][j]|used[b][i][j];
				if (!used[n+p][i][j]) flag=0;
			}
			if (!flag) ans=i-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}