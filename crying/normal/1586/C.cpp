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
const int MAXN=1e6+10;
string a[MAXN];
int b[MAXN],c[MAXN];
int n,m,q,l,r;
void solve(){
	if (c[r] - c[l] > 0)printf("NO\n");
    else printf("YES\n");
}
int main(){
	scanf("%d%d",&n,&m);
  	rep(i,1,n){ cin >> a[i]; a[i] = ' ' + a[i]; }
 	rep(i,2,n)rep(j,2,m){
   	 if (a[i][j-1] == 'X' && a[i-1][j] == 'X') {
    	  b[j] = 1;
    	}
  }
  rep(i,1,m){
    c[i] = c[i - 1] + b[i];
  }
  scanf("%d",&q);
  while (q--) {
   	scanf("%d%d",&l,&r);
   	solve();
  }
	return 0;
}