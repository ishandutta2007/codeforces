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
const int moder=1e9+7;
int T,n,m;
int cnt;
int power(int a,int n){
	if(!n)return 1;
	int tmp=power(a,n/2);tmp=(ll)tmp*tmp%moder;
	if(n&1)tmp=(ll)tmp*a%moder;
	return tmp;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		int cnt=0;
		rep(i,1,n){
			rep(j,1,m){
				char tmp;scanf(" %c",&tmp);
				if(tmp=='#')cnt++;
			}
		}
		int ans=power(2,cnt);
		if(cnt==n*m)ans=(ans-1+moder)%moder;
		printf("%d\n",ans);
	}

	return 0;
}