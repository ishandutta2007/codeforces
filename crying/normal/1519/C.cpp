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
const int MAXN=2e5+10;
int T,n,u[MAXN],s[MAXN],lim;
vector<int>S[MAXN];
ll ans[MAXN],sum[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		lim=sqrt(n)+1;
		rep(i,1,n){
			S[i].clear();ans[i]=0;
			scanf("%d",&u[i]);
		}
		rep(i,1,n){
			scanf("%d",&s[i]);
		}
		rep(i,1,n){
			S[u[i]].pb(s[i]);
		}
		rep(i,1,n){
			sort(S[i].begin(),S[i].end(),greater<int>());
		}
		rep(i,1,n){
			int sz=S[i].size();if(!sz)continue;
		//	printf("%d\n",i);
			// 
			sum[1]=S[i][0];
			rep(j,2,sz){
				sum[j]=sum[j-1]+S[i][j-1];
			}
			if(sz<=lim){
				//k>sz
			//	printf("\n");
				rep(k,1,sz){
					int rest=sz%k;
				//	printf("k:%d rest:%d(%lld)\n",k,rest,sum[sz-rest]);
					ans[k]+=sum[sz-rest];
				} 
			}else{
				//
			//	printf("\n");
				rep(k,1,n){
					int rest=sz%k; //rest
				//	printf("k:%d rest:%d(%lld)\n",k,rest,sum[sz-rest]);
					ans[k]+=sum[sz-rest]; 
				} 
			}
		}
		rep(i,1,n)printf("%lld ",ans[i]);
		printf("\n");
	}

	return 0;
}