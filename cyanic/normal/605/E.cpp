#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005;
ld f[N],g[N],prob[N],p[N][N];
int vis[N],n;

int main(){
	read(n);
	rep(i,1,n)rep(j,1,n){
		read(p[i][j]);
		p[i][j]/=100;
	}
	rep(i,1,n)f[i]=1e99;
	f[n]=0;
	rep(i,1,n){
		int u=0;
		rep(j,1,n){
			if(vis[j])continue;
			if(!u||f[j]<f[u])u=j;
		}
		vis[u]=1;
		rep(v,1,n)
			if(!vis[v]&&p[v][u]&&f[u]<f[v]+1){
				g[v]+=(1-prob[v])*p[v][u]*f[u];
				prob[v]+=(1-prob[v])*p[v][u];
				f[v]=g[v]/prob[v]+1/prob[v];
			}
	}
	printf("%.8lf\n",f[1]);
	return 0;
}