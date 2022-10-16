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
const int MAXN=310;
ll t,n,m,ans;
pair< pi,int> a[MAXN*MAXN];
ll ret[MAXN][MAXN];
bool cmp(const pair< pi,int>& p1,const pair< pi,int>& p2){
	if(p1.fr.fr!=p2.fr.fr)return p1.fr.fr<p2.fr.fr;
	return p1.fr.se<p2.fr.se;
}
bool cmp2(const pair<pi,int>& p1,const pair<pi ,int>& p2){
	return p1.fr.se<p2.fr.se;
}
ll S(ll n){
	return n*(n-1)/2;
}
void solve(){
	scanf("%lld%lld",&n,&m);
	rep(i,1,n){
		rep(j,1,m){
			ret[i][j]=0;
		} 
	}
	ans=0;
	rep(i,1,n)rep(j,1,m){
		scanf("%d",&a[(i-1)*m+j].fr.fr);
		a[(i-1)*m+j].fr.se=(i-1)*m+j;
	}
	sort(a+1,a+1+n*m,cmp);
	rep(i,1,n*m)a[i].se=i;
	sort(a+1,a+1+n*m,cmp2);
	rep(i,1,n*m){
		int x=(a[i].se-1)/m+1,y=(a[i].se-1)%m+1;
		rep(j,1,y-1)if(ret[x][j])ans++;
		ret[x][y]=a[i].fr.fr;
	}
	rep(i,1,n){
		ll val=0,len=0;
		ret[i][m+1]=-1;
		rep(j,1,m+1){
			if(ret[i][j]!=val){
				ans-=S(len);
				len=1;val=ret[i][j];
			}else{
				++len;
			}
		}
	}
	printf("%lld\n",ans);
}	
int main(){
	scanf("%lld",&t);
	while(t--){
		solve();
	}

	return 0;
}