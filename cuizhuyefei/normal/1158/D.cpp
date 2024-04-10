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
const int N = 102000;
int n,top;
struct dot {
	int x,y;
	dot(int X=0, int Y=0) {x=X; y=Y;}
} s[N],sta[N];
dot operator - (dot a, dot b) {return dot(a.x-b.x,a.y-b.y);}
ll operator * (dot a, dot b) {return 1LL*a.x*b.y-1LL*a.y*b.x;}
ll dis(dot a) {return 1LL*a.x*a.x+1LL*a.y*a.y;}
bool cmp(dot a, dot b) {ll t=a*b; return t!=0?t>0:dis(a)<dis(b);} 
//lenxydis not x!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
inline ll Abs(ll x) {return x>0?x:-x;}
bool gg[N];int ans[N];
int find(int st, int tp){
	int res=0;rep(i,1,n)if(!gg[i]){res=i;break;}
	rep(i,res+1,n)if(!gg[i]){
		if(((s[i]-s[st])*(s[res]-s[st])>0)==(tp==-1))res=i;
	}
	return res;
}
int main() {
	read(n); rep(i,1,n) read(s[i].x),read(s[i].y);
	static char S[N];scanf("%s",S+1);
	int tmp=1;rep(i,2,n)if(s[i].x<s[tmp].x||s[i].x==s[tmp].x&&s[i].y<s[tmp].y)tmp=i;
	ans[1]=tmp;gg[tmp]=1;ans[2]=find(ans[1],S[1]=='L'?-1:1);gg[ans[2]]=1;
	rep(i,2,n-1){
		ans[i+1]=find(ans[i],S[i]=='L'?-1:1);gg[ans[i+1]]=1;
	}
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}