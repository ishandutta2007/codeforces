#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 3333;
char s[N];int n,dp[N],pre[N];
bool gg[N][N],sp[N];
bool ck(char c){
	return !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	rep(i,1,n){
		bool vis[257]={0};int cnt=0;
		for(int j=i;j<=n&&ck(s[j]);j++){
			if(!vis[s[j]])cnt++;vis[s[j]]=1;
			if(cnt>=2&&j-i+1>=3)gg[i][j]=1;
		}
	}
	per(l,n,1)rep(r,l,n)if(gg[l][r])
		gg[l][r+1]=gg[l-1][r]=1;
	rep(i,1,n){
		dp[i]=1e9;
		rep(j,0,i-1)if(!gg[j+1][i]&&dp[i]>1+dp[j])
			dp[i]=1+dp[j],pre[i]=j;
	//	cerr<<pre[i]<<endl;
	}
	for(int i=pre[n];i;i=pre[i])sp[i]=1;/*{s.pb(i);if(!i)break;}
	reverse(s.begin(),s.end());*/
//	rep(i,1,n)printf("%d",sp[i]);puts("");
	rep(i,1,n){
		printf("%c",s[i]);if(sp[i])putchar(' ');
	}
	return 0;
}