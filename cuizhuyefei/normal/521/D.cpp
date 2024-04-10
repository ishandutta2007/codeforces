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
int k,n,m;ll a[N];bool ass[N];
struct node{
	int op,i,x,idx;double val;
}s[N];
bool cmp1(node a, node b){
	return a.x>b.x;
}
bool cmp2(node a, node b){
	return a.val>b.val;
}
bool cmp3(node a, node b){
	return a.op<b.op;
}
int main() {
	read(k);read(n);read(m);
	rep(i,1,k)read(a[i]);
	rep(i,1,n){
		read(s[i].op),read(s[i].i),read(s[i].x);
		s[i].idx=i;if(s[i].op==1)s[i].x-=a[s[i].i];
	}
	sort(s+1,s+n+1,cmp1);
	rep(i,1,n)
		if(s[i].op==1){
			if(!ass[s[i].i]){
				ass[s[i].i]=1;
				if(s[i].x>0)s[i].val=1.0*(s[i].x+a[s[i].i])/a[s[i].i],a[s[i].i]+=s[i].x;
			}
		}
		else if(s[i].op==2){
			s[i].val=1.0*(a[s[i].i]+s[i].x)/a[s[i].i];a[s[i].i]+=s[i].x;
		}
		else s[i].val=s[i].x;
	sort(s+1,s+n+1,cmp2);
	int p=0;rep(i,1,m)if(s[i].val>=1)p=i;
	if(p)sort(s+1,s+p+1,cmp3);
	printf("%d\n",p);
	rep(i,1,p)printf("%d ",s[i].idx);
	return 0;
}