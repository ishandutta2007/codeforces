#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=20,MAXM=(1<<20),INF=1e9;
int n,m,a[MAXN][MAXN],f[MAXM],g[MAXN][MAXN],h[MAXN][MAXN];
char s[MAXN][MAXN];
int main(){
	cin>>n>>m;
	rep(i,0,n-1){
		cin>>s[i];
	}
	rep(i,0,n-1){
		rep(j,0,m-1)cin>>a[i][j];
	}
	rep(i,0,n-1){
		rep(j,0,m-1){
			int maxn=-INF;
			rep(k,0,n-1){
				if(s[i][j]==s[k][j]){
					g[i][j]|=(1<<k);
					h[i][j]+=a[k][j];
					maxn=max(maxn,a[k][j]);
				}
			} 
			h[i][j]-=maxn;
		}
	}
	rep(i,1,(1<<n)-1)f[i]=INF;
	rep(i,0,(1<<n)-2){
		int j;
		rep(k,0,n-1){
			if(i&(1<<k))continue;
			j=k;break;
		}
		rep(pos,0,m-1){
			f[i | (1<<j)]=min(f[i | (1<<j)],f[i]+a[j][pos]);
			f[i | g[j][pos]]=min(f[i | g[j][pos]],f[i]+h[j][pos]);
		}
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
}