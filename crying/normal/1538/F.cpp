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
int d1[10],d2[10];
ll t,l,r,ans;
int main(){
	cin>>t;
	while(t--){
		cin>>l>>r;ans=0;
		rep(i,0,9){
			d1[i]=l%10;
			d2[i]=r%10;
			l/=10;r/=10;
		}
		ll pre1=0,pre2=0;
		per(i,9,0){
			ll cnt=pre2-pre1; //
			ans+=(cnt-1)*10+(10-d1[i]);
			ans+=d2[i]; 
			pre1=pre1*10+d1[i];
			pre2=pre2*10+d2[i];
		}
		cout<<ans<<endl;
	}

	return 0;
}