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
const int N = 266666;
char S[N];int n,a[N],nxt[N],res;Vi b[2][2];//a[i],jiou
Vi c[2][N];int l0,l1;Vi c10,c01;bool head[N];
int q[N],f,r;
void pushr(Vi c){
	if(f<=r)assert(a[q[r]]!=a[c[0]]);rep(i,0,SZ(c)-1)q[++r]=c[i];
}
void pushl(Vi c){
	if(f<=r)assert(a[q[f]]!=a[c.back()]);per(i,SZ(c)-1,0)q[--f]=c[i];
}
int main() {
	scanf("%s",S+1);n=strlen(S+1);
	rep(i,1,n)a[i]=S[i]=='L';
	per(i,n,1){
		if(SZ(b[a[i]^1][0])){
			nxt[i]=b[a[i]^1][0].back();
			b[a[i]^1][0].pop_back();b[a[i]][1].pb(i);
		}
		else if(SZ(b[a[i]^1][1])){
			nxt[i]=b[a[i]^1][1].back();
			b[a[i]^1][1].pop_back();b[a[i]][0].pb(i);
		}else res++,b[a[i]][1].pb(i);
	}
	rep(i,1,n)head[i]=1;rep(i,1,n)head[nxt[i]]=0;
	rep(s,1,n)if(head[s]){
		Vi d;for(int i=s;i;i=nxt[i])d.pb(i);
		if(SZ(d)%2==1){
			if(a[s]==0)c[0][++l0]=d;else c[1][++l1]=d;
		}
		else if(a[s]==0){rep(i,0,SZ(d)-1)c01.pb(d[i]);}
		else{rep(i,0,SZ(d)-1)c10.pb(d[i]);}
	}
	f=n+1;r=n;//[f,r]
	int zuo=0,you=0;
	if(SZ(c10)&&SZ(c01)){
		assert(l0+l1);
		if(l1>l0){
			pushr(c[1][l1--]);pushr(c01);pushl(c10);
			zuo=1;you=1;
		}
		else{
			pushr(c[0][l0--]);pushr(c10);pushl(c01);
			zuo=0;you=0;
		}
	}
	else if(SZ(c10)){
		pushr(c10);zuo=1;you=0;
	}
	else if(SZ(c01)){
		pushr(c01);zuo=0;you=1;
	}
	else if(l0)pushr(c[0][l0--]),zuo=you=0;
	else pushr(c[1][l1--]),zuo=you=1;
	assert(l0>=0&&l1>=0);
	while(l0+l1){
		if(you==1&&l0)pushr(c[0][l0--]),you=0;
		else if(zuo==1&&l0)pushl(c[0][l0--]),zuo=0;
		else if(you==0&&l1)pushr(c[1][l1--]),you=1;
		else pushl(c[1][l1--]),zuo=1;
	}
	printf("%d\n",res-1);
	rep(i,f,r)printf("%d ",q[i]);
	return 0;
}