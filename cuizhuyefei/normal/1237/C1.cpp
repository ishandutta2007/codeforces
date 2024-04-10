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
const int N = 56666;
bool gg[N];
struct dot{
	int x,y,z,id;
}s[N];int n;Pii ans[N];int sz;
bool cmp(dot a, dot b){return a.x!=b.x?a.x<b.x:(a.y!=b.y?a.y<b.y:a.z<b.z);}
int main() {
	read(n);
	rep(i,1,n)read(s[i].x),read(s[i].y),read(s[i].z),s[i].id=i;
	sort(s+1,s+n+1,cmp);
	//1
	rep(i,1,n)gg[i]=0;
	rep(i,1,n){
		int j=i;while(j+1<=n&&s[j+1].x==s[i].x&&s[j+1].y==s[i].y)j++;
		for(int k=i;k+1<=j;k+=2)gg[k]=gg[k+1]=1,ans[++sz]=Pii(s[k].id,s[k+1].id);
		i=j;
	}
	int len=0;rep(i,1,n)if(!gg[i])s[++len]=s[i];n=len;
	//2
	rep(i,1,n)gg[i]=0;
	rep(i,1,n){
		int j=i;while(j+1<=n&&s[j+1].x==s[i].x)j++;
		for(int k=i;k+1<=j;k+=2)gg[k]=gg[k+1]=1,ans[++sz]=Pii(s[k].id,s[k+1].id);
		i=j;
	}
	len=0;rep(i,1,n)if(!gg[i])s[++len]=s[i];n=len;
	//3
	for(int i=1;i+1<=n;i+=2)ans[++sz]=Pii(s[i].id,s[i+1].id);
	
	rep(i,1,sz)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}