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
const int N = 1020000;
int cnt[2],n,m;char s[N],t[N];
int nxt[N],len,ans[N];
void put(int c){
	c-='0';
	if(cnt[c])cnt[c]--,ans[++len]=c;
}
int main() {
	scanf("%s%s",t+1,s+1);
	m=strlen(t+1);rep(i,1,m)cnt[t[i]-'0']++;
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[i]!=s[j+1])j=nxt[j];
		if(s[i]==s[j+1])j++;nxt[i]=j;
	}
	rep(i,1,n)put(s[i]);
	if(len==n){
		while(1){
			int rec=len;
			rep(i,nxt[n]+1,n)put(s[i]);
			if(len-rec!=n-nxt[n])break;
		}
	}
	while(cnt[0])ans[++len]=0,cnt[0]--;
	while(cnt[1])ans[++len]=1,cnt[1]--;
	rep(i,1,len)printf("%d",ans[i]);
	return 0;
}