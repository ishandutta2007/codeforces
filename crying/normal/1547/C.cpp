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
const int MAXN=610;
ll T,k,n,m,a[MAXN],b[MAXN],ret[MAXN];
int main(){
	cin>>T;
	while(T--){
		cin>>k>>n>>m;
		rep(i,1,n){
			cin>>a[i];
		}
		rep(i,1,m){
			cin>>b[i];
		}
		ll L=1,R=1,tot=0;
		while(L<=n && R<=m){
			if(a[L]<=b[R]){
				ret[++tot]=a[L];
				L++;
			}else{
				ret[++tot]=b[R];
				R++;
			}
		}
		while(L<=n){
			ret[++tot]=a[L];
			L++;
		}
		while(R<=m){
			ret[++tot]=b[R];
			R++;
		}
		ll sum=k,flag=1;
		rep(i,1,n+m){
			if(ret[i]==0){
				sum++;
			}else{
				if(sum<ret[i]){
					flag=0;break;
				}
			}
		}
		if(!flag)printf("-1\n");
		else{
			rep(i,1,n+m){
				printf("%lld ",ret[i]);
			}
			printf("\n");
		}
	}

	return 0;
}