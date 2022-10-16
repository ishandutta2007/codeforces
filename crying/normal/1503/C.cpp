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
const int MAXN=2e5+10;
pi a[MAXN];
ll n,ans,idx,pre[MAXN]; 
int LowerBound(int val){
	//val 
	int L=1,R=n,ans=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(a[mid].fr<=val){
			ans=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	return ans;
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i].fr>>a[i].se;ans+=a[i].se;
	} 
	sort(a+1,a+1+n);
	rep(i,1,n){
		pre[i]=Max(pre[i-1],a[i].fr+a[i].se);
	}
	idx=1;
	while(idx<n){
		int pos=LowerBound(pre[idx]);
		if(pos==n)break;
		//pos+1
		ans+=Max(0,a[pos+1].fr-pre[pos]); 
		idx=pos+1;
	}
	cout<<ans;
	return 0;
}