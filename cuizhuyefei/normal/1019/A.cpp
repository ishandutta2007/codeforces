#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 55666;
int n,m,s[N];Vi a[N];
int main() {//freopen("1.in","r",stdin);
	read(n);read(m);rep(i,1,n){
		int x,y;read(x);read(y);a[x].pb(y);
	}
	rep(i,1,m)sort(a[i].begin(),a[i].end());ll res=1e18;
	rep(i,max(SZ(a[1]),1),n){
		int cnt=i-SZ(a[1]),len=0;ll cost=0;
		rep(j,2,m){
		//	printf("j = %d %d %d\n",j,SZ(a[j]),i);
			if(SZ(a[j])<i)per(k,SZ(a[j])-1,0)s[++len]=a[j][k];
			else{
				int pos=SZ(a[j])-1;
				rep(k,pos-i+2,pos)s[++len]=a[j][k];pos=pos-i+1;
				while(pos>=0)cost+=a[j][pos],pos--,cnt--;
			}
		}
	//	printf("%d %d\n",cnt,len);
		if(cnt<0)continue;
		if(cnt){
			sort(s+1,s+len+1);rep(j,1,cnt)cost+=s[j];
		}
		res=min(res,cost);
	}
	printf("%lld\n",res);
	return 0;
}