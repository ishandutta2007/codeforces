#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
ll n,a[MAXN],ans,sum,cnt;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		if(a[i]<2){
			sum+=a[i];
			continue;
		}
		cnt=Min(a[i]/2,sum);
		ans+=cnt;
		sum-=cnt;a[i]-=cnt*2;
		cnt=a[i]/3;
		ans+=cnt;
		a[i]-=cnt*3;
		sum+=a[i];
	}
	cout<<ans;
	return 0;
}