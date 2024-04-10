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
const int MAXN=2e5+10;
int T,n,a[MAXN];
deque<int>ret;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ret.clear();
		rep(i,1,n)scanf("%d",&a[i]);
		ret.pb(a[1]);
		rep(i,2,n){
			if(a[i]<ret.front())ret.push_front(a[i]);
			else ret.pb(a[i]); 
		}
		rep(i,0,n-1)printf("%d ",ret[i]);printf("\n");
	}

	return 0;
}