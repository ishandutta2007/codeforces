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
const int MAXN=110;
int T,n,k,p[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		if(k>(n-1)/2){
			printf("-1\n");continue;
		} 
		rep(i,1,n)p[i]=0;
		rep(i,1,k){
			p[2*i]=n-i+1;
		}
		int use=n-k;
		rep(i,1,n){
			if(!p[i])p[i]=use--;
			printf("%d ",p[i]);
		}
		printf("\n");
	}

	return 0;
}