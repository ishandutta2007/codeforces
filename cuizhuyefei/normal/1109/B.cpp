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
const int N = 66666;
char s[N],t[N];int n,cnt[6666],res;
bool Is(char *s,int l, int r){
	rep(i,l,r)if(s[i]!=s[r-i+1])return 0;
	return 1;
}
int main() {
	scanf("%s",s+1);int n=strlen(s+1);
	rep(i,1,n/2)cnt[s[i]-'a']++;
	int tot=0;rep(i,0,300)tot+=cnt[i]>0;
	if(tot<=1){puts("Impossible");return 0;}
	res=(!(n&1)&&!Is(s,1,n/2))?1:2;
	rep(i,1,n-1){
		int len=0;
		rep(j,i+1,n)t[++len]=s[j];
		rep(j,1,i)t[++len]=s[j];
		if(Is(t,1,n)){
			bool ok=0;rep(j,1,n)ok|=t[j]!=s[j];
			if(ok)res=1;
		}
	}
	printf("%d",res);
	return 0;
	
}