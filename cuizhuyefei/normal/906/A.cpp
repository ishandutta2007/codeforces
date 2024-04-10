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
const int N = 505000;
int n;

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
char s[N];
bool gg[27];
int cnt[27];
inline void print(int p) {
	int ans=0; //printf("print %d\n",p);
	rep(i,p,n) {
		char tp[3]; scanf("%s%s",tp,s); int len=strlen(s);
		bool wa=1; rep(j,0,len-1) if (!gg[s[j]-'a']) wa=0;
		if (i<n) if (tp[0]=='!'||(tp[0]=='?'&&wa)) ans++;
	} printf("%d",ans);
}
int main() { //freopen("1.in","r",stdin);
	read(n);
	rep(i,1,n) {
		char tp[3]; scanf("%s%s",tp,s);
	//	printf("[%d %d %d]\n",strlen(tp),strlen(s),gg['c'-'a']);
		memset(cnt,0,sizeof(cnt));
		int len=strlen(s);
		rep(j,0,len-1) cnt[s[j]-'a']++;
		if (tp[0]=='.') {
			rep(j,0,25) if (cnt[j]) gg[j]=1;
		}
		else if (tp[0]=='!') {
			rep(j,0,25) if (!cnt[j]) gg[j]=1;
		}
		else {if (i<n) gg[s[0]-'a']=1;}
		int num=0; rep(j,0,25) num+=(!gg[j]);
	//	printf("<%d %d %d>\n",i,num,gg['c'-'a']);
		if (num==1) {print(i+1); return 0;}
	}
	puts("0"); return 0;
}