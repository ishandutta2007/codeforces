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
const int N = 55;
int n,m,zh[N];Pii a[N],b[N];
int v[N][N];vector<Vi>ans1,ans2,ans;
void move(int a, int b, int c, int d){
	assert(v[a][b]&&!v[c][d]);
	v[c][d]=v[a][b];v[a][b]=0;ans.pb({a,b,c,d});
}
void solve(){
	ans.clear();memset(v,0,sizeof(v));
	rep(i,1,m)v[a[i].fi][a[i].se]=i;
	rep(k,1,m){
		bool fd=0;
		rep(i,k,n)rep(j,k,n)if(!fd&&v[i][j]){
			fd=1;int x=i,y=j;
			while(y>k)move(x,y,x,y-1),y--;
			while(x>k)move(x,y,x-1,y),x--;
		}
		rep(j,k+1,n)if(v[k][j]){
			int i=k;while(v[i][j])i++;
			per(c,i-1,k)move(c,j,c+1,j);
		}
		rep(i,k+1,n)if(v[i][k]){
			int j=k;while(v[i][j])j++;
			per(c,j-1,k)move(i,c,i,c+1);
		}
	}
	if(!zh[1]){
		rep(i,1,m)zh[v[i][i]]=i;
	}
	rep(i,1,m)v[i][i]=zh[v[i][i]];
	rep(i,1,m)per(j,m,i+1)if(v[j-1][j-1]>v[j][j]){
		move(j,j,j,j-1);
		move(j-1,j-1,j-1,j);
		move(j,j-1,j-1,j-1);
		move(j-1,j,j,j);
	}
}
int main() {
	read(n);read(m);
	rep(i,1,m)read(a[i].fi),read(a[i].se);
	solve();ans1=ans;
	rep(i,1,m)read(a[i].fi),read(a[i].se);
	solve();ans2=ans;
	reverse(ALL(ans2));
	for(auto &x:ans2)swap(x[0],x[2]),swap(x[1],x[3]);
	ans1.insert(ans1.end(),ALL(ans2));
	printf("%d\n",SZ(ans1));
	for(auto x:ans1){for(int y:x)printf("%d ",y);puts("");}
	return 0;
}