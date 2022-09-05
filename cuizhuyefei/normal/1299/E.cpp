#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 808;
int n,a[N],ji[N],f3[N],f5[N],f7[N],f8[N],pos[N];
int Hi[]={0,3,6,12,2,14,5,10,1,13,4,11,9,8,7};
int ask(Vi res){
	printf("? %d ",SZ(res));for(int x:res)printf("%d ",x);puts("");fflush(stdout);
	int x=0;
//	for(int y:res)x+=Hi[y];x=x%SZ(res)==0;
	read(x);
	return x;
}
Vi sub(Vi a, Vi b){
	sort(ALL(a));sort(ALL(b));
	int p=0;Vi res;
	for(int x:a)if(p<SZ(b)&&b[p]==x)p++;else res.pb(x);
	return res;
}
int main() {
	read(n);Vi all;rep(i,1,n)all.pb(i);Vi cc;
	rep(i,1,n)if(ask(sub(all,{i})))cc.pb(i);
	assert(SZ(cc)==2);a[cc[0]]=1;a[cc[1]]=n;
	rep(i,1,n)if(!a[i])ji[i]=ask({cc[0],i});
	rep(k,1,min(4,n/2)-1){//n-2*k
		Vi tot;rep(i,1,n)if(!a[i])tot.pb(i);
		Vi dd;for(int x:tot)if(ask(sub(tot,{x})))dd.pb(x);
		assert(SZ(dd)==2);if(ji[dd[0]]==(k+1)%2)a[dd[0]]=k+1;else a[dd[0]]=n-k;
		a[dd[1]]=n+1-a[dd[0]];
	}
	if(n<=8){
		if(a[1]>n/2){rep(i,1,n)a[i]=n+1-a[i];}
		printf("! ");rep(i,1,n)printf("%d ",a[i]);return 0;
	}
	rep(i,1,n)pos[a[i]]=i;
	//8
	rep(i,1,n)if(!a[i]){
		a[i]=ji[i];Vi b={i,pos[1],pos[2],pos[3]};if(a[i]+6&1)b.pop_back(),b.pb(pos[4]);
		int x=ask(b)?4:2;rep(j,1,SZ(b)-1)x-=a[b[j]];x=(x%4+4)%4;a[i]=x;
		int cut=(a[i]+n*4-6+10)%4;
		b={i,pos[n],pos[n-1],pos[n-2],pos[n-3]};
		rep(j,1,4)if((j-cut)%4)b.pb(pos[j]);
		assert(SZ(b)==8);x=ask(b)?8:4;rep(j,1,SZ(b)-1)x-=a[b[j]];x=(x%8+8)%8;f8[i]=x;a[i]=0;
	}
	//7
	rep(i,1,n)if(!a[i]){
		bool ok=0;int x,y;
		x=1;rep(y,n-3,n)if(!ok){
			Vi b={i};rep(i,1,4)if(i!=x)b.pb(pos[i]);rep(i,n-3,n)if(i!=y)b.pb(pos[i]);
			if(ask(b)){ok=1;for(int x:b)f7[i]-=a[x];f7[i]=(f7[i]%7+7)%7;}
		}
		x=4;rep(y,n-2,n)if(!ok){
			Vi b={i};rep(i,1,4)if(i!=x)b.pb(pos[i]);rep(i,n-3,n)if(i!=y)b.pb(pos[i]);
			if(y==n||ask(b)){ok=1;for(int x:b)f7[i]-=a[x];f7[i]=(f7[i]%7+7)%7;}
		}
	}
	//5
	rep(i,1,n)if(!a[i]){
		bool ok=0,vis[5]={0};
		rep(x,1,4)if(!ok){
			Vi b={i,pos[x]};rep(j,n-2,n)b.pb(pos[j]);
			int t=0;for(int x:b)t-=a[x];t=(t%5+5)%5;assert(!vis[t]);vis[t]=1;
			if(ask(b)){ok=1;f5[i]=t;}
		}
		if(!ok)rep(j,0,4)if(!vis[j])f5[i]=j;
	}
	//3
	rep(i,1,n)if(!a[i]){
		bool ok=0,vis[3]={0};
		rep(x,1,2)if(!ok){
			Vi b={i,pos[x],pos[n]};
			int t=0;for(int x:b)t-=a[x];t=(t%3+3)%3;assert(!vis[t]);vis[t]=1;
			if(ask(b)){ok=1;f3[i]=t;}
		}
		if(!ok)rep(j,0,2)if(!vis[j])f3[i]=j;
	}
	rep(i,1,n)if(!a[i]){
		rep(j,1,n)if(j%3==f3[i]&&j%5==f5[i]&&j%7==f7[i]&&j%8==f8[i]){
			a[i]=j;break;
		}
	}
	if(a[1]>n/2){rep(i,1,n)a[i]=n+1-a[i];}
	printf("! ");rep(i,1,n)printf("%d ",a[i]);
	return 0;
}