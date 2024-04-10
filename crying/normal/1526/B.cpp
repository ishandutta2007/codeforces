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
const ll MAXN=15,MAXM=200,INF=1e18;
int t,n;
int f[1100];
int main(){
	scanf("%d",&t);
	f[0]=1;
	rep(i,1,1099){
		if(i>=11)f[i]=f[i]|f[i-11];
		if(i>=111)f[i]=f[i]|f[i-111];
	}
	while(t--){
		scanf("%d",&n);
		if(n>1099)printf("YES\n");
		else{
			if(f[n])printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}