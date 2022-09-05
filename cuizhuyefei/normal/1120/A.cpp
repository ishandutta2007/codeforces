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
const int N = 505000;
int m,k,n,s;
int a[N],b[N],buc[N];
void GG(){puts("-1");exit(0);}
void ck(int l, int r){
	int x=(l+k-1)/k,y=(r+k-1)/k;
//	printf("%d %d %d %d\n",l,r,x,y);
	if(m-max(r-x*k,0)>=k*n){
		Vi s;
		per(i,r,1)if(buc[a[i]]>0&&(r+k-1)/k>x)buc[a[i]]--,s.pb(i),r--;
		printf("%d\n",SZ(s));rep(i,0,SZ(s)-1)printf("%d ",s[i]);
		exit(0);
	}
}
int main() {
	read(m);read(k);read(n);read(s);
	rep(i,1,m)read(a[i]);
	rep(i,1,s)read(b[i]),buc[b[i]]--;
	rep(i,1,m)buc[a[i]]++;
	rep(i,1,s)if(buc[b[i]]<0)GG();
	int j=m;while(j>=1&&buc[a[j]]-1>=0)buc[a[j]]--,j--;
	for(int i=1;i<=m;i++){
		if(j>m)break;
		ck(i,j);
		buc[a[i]]--;
		if(buc[a[i]]<0){
			while(j<=m&&buc[a[i]]<0)j++,buc[a[j]]++;
		}
	//	printf("[%d %d]\n",i,j);
	}
	puts("-1");
	return 0;
}