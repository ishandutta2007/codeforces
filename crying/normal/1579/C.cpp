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
const int MAXN=30;
int T,n,m,k,vis[MAXN][MAXN];
char s[MAXN][MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		rep(i,1,n)rep(j,1,m)cin>>s[i][j];
		memset(vis,0,sizeof vis);
		rep(i,1,n)rep(j,1,m){
			if(s[i][j]=='*'){
				int d=0;
				rep(k,1,i-1){
					if(j-k<0||j+k>m)break;
					if(s[i-k][j-k]!='*' || s[i-k][j+k]!='*')break;
					d++;
				}
				rep(k,0,d){
					vis[i-k][j-k]=max(vis[i-k][j-k],d);
					vis[i-k][j+k]=max(vis[i-k][j+k],d);
				}
			}
		}
		int flag=1;
		rep(i,1,n)rep(j,1,m){
			if(s[i][j]=='*' && vis[i][j]<k)flag=0;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}