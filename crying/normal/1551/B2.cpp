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
const ll MAXN=2e5+10;
ll t,n,k,a[MAXN],bucket[MAXN],ans,sum;
ll ret[MAXN];
vector<ll>v[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		rep(i,1,n){bucket[i]=0;ret[i]=0;v[i].clear();}
		rep(i,1,n){
			cin>>a[i];
			bucket[a[i]]++; 
			v[a[i]].pb(i);
		}
		sum=0;
		rep(i,1,n){
			if(bucket[i]>=k){
				rep(j,0,k-1){
					ret[v[i][j]]=j+1;
				}
			}
			else sum+=bucket[i];
		}
		sum/=k;
		ll use=1,now=1;
		rep(i,1,n){
			if(bucket[i]<k){
				rep(j,0,bucket[i]-1){
					ll pos=v[i][j];
					if(use>sum*k)break;
					ret[pos]=now;
					use++;
					now++;if(now>k)now=1;
				}
			}
		}
		rep(i,1,n)printf("%lld ",ret[i]);
		printf("\n");
	}

	return 0;
}
/*
1
13 3
3 1 4 1 5 9 2 6 5 3 5 8 9
*/