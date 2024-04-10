#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=200005;
int x[N],y[N],t[N],f[N],g[N],r,n,ans;

int dist(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main(){
	read(r),read(n);
	memset(f,0xc0,sizeof f);
	memset(g,0xc0,sizeof g);
	x[0]=y[0]=1,t[0]=0;
	rep(i,1,n){
		read(t[i]),read(x[i]),read(y[i]);
	}
	f[0]=0;
	rep(i,0,n){
		g[i+1]=max(g[i+1],g[i]);
		f[i]=max(f[i],g[i]);
		ans=max(ans,f[i]);
		rep(j,1,r*2) if(i+j<=n){
			if(dist(i,i+j)<=t[i+j]-t[i]){
				f[i+j]=max(f[i+j],f[i]+1);
			}
		}
		if(i+r*2+1<=n){
			g[i+r*2+1]=max(g[i+r*2+1],f[i]+1);
		}
	}
	printf("%d\n",ans);
	return 0;
}