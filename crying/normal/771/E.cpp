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
const int MAXN=3e5+10,INF=1e9;
ll n,a[3][MAXN],s[3][MAXN],pre[3][MAXN];
map<ll,int>qwq;
map<pi,int>f;
int dp(int i,int j){
	if(i<0 || j<0)return -INF;
	if(f.count(mp(i,j)))return f[mp(i,j)];
	int pos=min(i,j);
	int ret=1+dp(pre[0][pos],pre[0][pos]);
	if(pre[1][i]>=pre[2][j]){
		ret=max(ret,dp(pre[1][i],j)+1);
	}else{
		ret=max(ret,dp(i,pre[2][j])+1);
	}
	ret=max(ret,0);
	return f[mp(i,j)]=ret;
}
int main(){
	cin>>n;
	rep(i,1,2){
		rep(j,1,n){
			cin>>a[i][j];
		}
		rep(j,1,n){
			s[0][j]+=a[i][j];
			s[i][j]+=a[i][j];
		}
	}
	rep(i,0,2)rep(j,1,n)s[i][j]+=s[i][j-1];
	pre[0][0]=pre[1][0]=pre[2][0]=-1;
	rep(i,0,2){
		qwq.clear();
		qwq[0]=0;
		rep(j,1,n){
			if(qwq.count(s[i][j]))pre[i][j]=qwq[s[i][j]];
			else pre[i][j]=-1;
			pre[i][j]=max(pre[i][j],pre[i][j-1]);
			qwq[s[i][j]]=j;
		}
	}
	cout<<dp(n,n);
	return 0;
}