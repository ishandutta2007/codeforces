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
const ll MAXN=110;
ll T,n;
char ret[MAXN];
vector<string>ans[MAXN];
int main(){
	rep(n,1,50){
		rep(i,0,n-1){
			rep(j,1,2*i){
				if(odd(j))ret[j]='(';
				else ret[j]=')';
			}
			ll rest=(2*n-2*i)/2;
			rep(j,2*i+1,2*i+rest)ret[j]='(';
			rep(j,2*i+rest+1,2*n)ret[j]=')';
			ans[n].pb(ret+1);
		}

	}
	cin>>T;
	while(T--){
		cin>>n;
		for(auto ret:ans[n]){
			cout<<ret<<endl;
		}
	}
	return 0;
}