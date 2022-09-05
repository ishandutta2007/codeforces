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
int n,k,a[N];
bitset<2020>f[1<<16|3];
Vi dot[N];
int main() {
	read(n);read(k);rep(i,1,n)read(a[i]);
	f[0][0]=1;int all=(1<<n)-1;
	rep(s,0,all){
		per(i,2000/k,0)if(f[s][i*k])f[s][i]=1;
		rep(i,1,n)if(!(s>>i-1&1))f[s|(1<<i-1)]|=f[s]<<a[i];
	}
	if(!f[all][1]){puts("NO");return 0;}
	puts("YES");
	static int val[N],lzy[N];int len=0,s=all,x=1;
	while(len<n){
		rep(i,1,n)if((s>>i-1&1)&&x>=a[i]&&f[s^(1<<i-1)][x-a[i]])
			val[++len]=a[i],s^=1<<i-1,x-=a[i];
		if(x*k<=2000&&f[s][x*k])x*=k,lzy[len+1]++;
	}
	rep(i,1,len)lzy[i]+=lzy[i-1],dot[lzy[i]].pb(val[i]);
//	rep(i,1,len)cerr<<val[i]<<' '<<lzy[i]<<endl;
	int mx=N-1;
	rep(tt,1,n-1){
		while(!SZ(dot[mx]))mx--;
		int i=mx;
			assert(SZ(dot[i])>=2);
			int x=dot[i].back();dot[i].pop_back();
			int y=dot[i].back();dot[i].pop_back();
			printf("%d %d\n",x,y);
			x+=y;int c=i;
			while(x%k==0)x/=k,c--;assert(c>=0);
			dot[c].pb(x);
	}
	rep(i,1,N-1)assert(!SZ(dot[i]));
	assert(SZ(dot[0])==1&&dot[0].back()==1);
	return 0;
}