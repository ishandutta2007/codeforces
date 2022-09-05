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
const int N = 2666666;
int n;char s[N],t[N];
bool ck(){
	int sum=0;
	rep(i,1,n)
		if(s[i]=='(')sum++;
		else{sum--;if(sum<0)return 0;}
	return sum==0;
}
int main() {
	read(n);scanf("%s",s+1);
	int x=n+1,y=0,q=0;
	per(i,n,1)if(s[i]==')')x=i;
	rep(i,1,n)if(s[i]=='(')y=i;
//	if(x<y)swap(s[x],s[y]);
	if(ck()){puts("Yes");return 0;}
	rep(i,1,n)t[i]=s[i];q=0;
	if(y>=1&&y<=n){
		s[++q]=t[y];
		rep(i,1,n)if(i!=y)s[++q]=t[i];
		if(ck()){puts("Yes");return 0;}
	}
	rep(i,1,n)s[i]=t[i];q=0;
	if(x>=1&&x<=n){
		rep(i,1,n)if(i!=x)s[++q]=t[i];
		s[++q]=t[x];
		if(ck()){puts("Yes");return 0;}
	}
	/**/
	if(ck()){puts("Yes");return 0;}
	puts("No");
	return 0;
}