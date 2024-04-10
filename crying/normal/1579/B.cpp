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
const int MAXN=60;
int T,n,a[MAXN],tmp[MAXN];
vector<pi>ret;
void remove(int l,int r,int k){
	rep(i,1,n)tmp[i]=a[i];
	rep(i,l,r){
		int idx=i-k;
		if(idx<l){idx+=(r-l+1);}
		tmp[idx]=a[i];
	}
	rep(i,1,n)a[i]=tmp[i];
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		ret.clear();
		rep(i,1,n-1){
			int maxn=0;
			rep(j,i,n){
				if(maxn==0 || a[maxn]>a[j])maxn=j;
			}
			if(maxn==i)continue;
			int d=maxn-i;
			remove(i,n,d);
			ret.pb(mp(i,d));
		}
		int sz=ret.size();
		printf("%d\n",sz);
		if(sz!=0){
			for(auto info:ret){
				printf("%d %d %d\n",info.fr,n,info.se);
			}
		}
	}

	return 0;
}