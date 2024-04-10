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
const int MAXN=2010;
int T,n,s,ans;
int main(){
//	cin>>T;
	T=1;
	while(T--){
		cin>>n;
		//cin>>s;
		s=0;
		if(s==1){
			ans=(n+1)/2;
			cout<<ans<<endl;
			continue;
		}
		ans=(n+1)/2;
		per(j,30,0){
			if(n>=(1<<j)){
				int rest=n-(1<<j);
				if(even(rest))ans=Min(ans,rest/2);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}