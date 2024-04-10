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
const int MAXN=2e5+10,MAXM=30,moder=1e9+7;
int T,n,a[MAXN],cnt[MAXM],val[MAXN][MAXM],vis[MAXN],tot;
ll ans=1;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);tot=0;
		memset(cnt,0,sizeof cnt);
		rep(i,1,n){
			vis[i]=1; // 
			scanf("%d",&a[i]);
			rep(j,0,29){
				val[i][j]=a[i]&1;
				a[i]>>=1;
			}
			rep(j,0,29)cnt[j]+=val[i][j];
		}
		rep(i,1,n){
			rep(j,0,29){
				if(cnt[j]==n)continue;
				if(val[i][j]){
					vis[i]=0;break;
				}
			}
		}
		rep(i,1,n)tot+=vis[i];
		ans=(ll)(tot)*(tot-1)%moder;
		rep(i,2,n-2){
			ans=ans*i%moder;
		}
		printf("%lld\n",ans);
	}

	return 0;
}