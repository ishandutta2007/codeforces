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
const int MAXN=18,MAXM=(1<<18);
int n;
db p[MAXN][MAXN];
db f[MAXM][MAXN];
void dp(){
	f[(1<<n)-1][0]=1;	
	per(mask,(1<<n)-2,1){
		rep(j,0,n-1){
			if(!(mask>>j&1))continue;
			if(j!=0 && (mask&1))continue;
			db& ret=f[mask][j];
			rep(k,0,n-1){
				if(mask>>k&1)continue;
				ret=max(ret,p[j][k]*f[mask|(1<<k)][j]+p[k][j]*f[mask|(1<<k)][k]);
			}
		//	printf("f[%d][%d]:%f\n",mask,j,f[mask][j]);
		}
	}
}
int main(){
	cin>>n;
	rep(i,0,n-1)rep(j,0,n-1)cin>>p[i][j];
	dp();
	db ret=0;
	rep(i,0,n-1)ret=max(ret,f[(1<<i)][i]);
	printf("%f",ret);

	return 0;
}