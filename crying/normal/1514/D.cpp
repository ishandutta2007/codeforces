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
const int MAXN=3e5+10;
int n,q,a[MAXN],l,r;
vector<int>v[MAXN];
int main(){
	srand(time(0));
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%d",&a[i]);
		v[a[i]].pb(i);
	}
	rep(i,1,q){
		scanf("%d%d",&l,&r);
		int ans=1;
		rep(j,1,30){
			int idx=0;
			rep(k,1,10){idx+=rand()*2;}
			idx%=(r-l+1);idx+=l;
			int num=a[idx];
			int L=lower_bound(v[num].begin(),v[num].end(),l)-v[num].begin();
			int R=lower_bound(v[num].begin(),v[num].end(),r+1)-v[num].begin();
			if((R-L)>(r-l+2)/2){ans=2*(R-L)-(r-l+1);break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}