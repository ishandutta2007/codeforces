#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=101,MAXM=1e4+1;
bool f[MAXN][MAXN][MAXM];
int n,m,T,k;
int main(){
	f[1][1][0]=1;
	rep(i,1,100){
		rep(j,1,100){
			rep(k,0,1e4){
				if(!f[i][j][k])continue;
				if(j<100 && k+i<1e4)f[i][j+1][k+i]=1;
				if(i<100 && k+j<1e4)f[i+1][j][k+j]=1;
			}
		}
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		if(f[n][m][k]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}