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
const int N = 1050;
int n,p[N],sta[N],top,a,pos[N],d[N];ll b[N];
int id[N],len;
ll qry1(int i, int j, int k){
	printf("1 %d %d %d\n",i,j,k);
	fflush(stdout);
	ll x;read(x);return x;
}
ll qry(int i, int j, int k){
	printf("2 %d %d %d\n",i,j,k);
	fflush(stdout);
	ll x;read(x);return x;
}
bool cmp(int x,int y){
	if(d[x]!=d[y])return d[x]>d[y];
	if(d[x]>0)return b[x]<b[y];
	return b[x]>b[y];
}
int main() {
	read(n);
	rep(i,2,n)sta[++top]=i;
	while(top>1){
		int x=sta[top--];
		int y=sta[top--];
		ll c=qry(1,x,y);
		if(c>0)sta[++top]=x;else sta[++top]=y;
	}
	a=sta[top];pos[1]=1;pos[a]=2;
	int c=0;
	rep(i,1,n)if(!pos[i]){
		b[i]=qry1(1,a,i);
		if(b[i]>b[c])c=i;
	}
	rep(i,1,n)if(!pos[i]&&i!=c)
		d[i]=qry(c,a,i);
	rep(i,1,n)if(!pos[i])id[++len]=i;
	sort(id+1,id+len+1,cmp);
	p[1]=1;p[2]=a;rep(i,1,len)p[2+i]=id[i];
	printf("0 ");
	rep(i,1,n)printf("%d ",p[i]);
	fflush(stdout);
	return 0;
}