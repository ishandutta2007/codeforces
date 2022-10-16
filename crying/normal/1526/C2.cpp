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
const ll MAXN=2e5+10,INF=1e18;
ll n,a[MAXN];
struct Node{
	ll val;
	bool operator<(const Node& n2)const{
		return val>n2.val;
	}
};
priority_queue<Node>h;
ll sum,ans;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	rep(i,1,n){
		sum+=a[i];h.push((Node){a[i]});
		while(sum<0){
			sum-=h.top().val;h.pop();
		}
	}
	cout<<h.size();
	return 0;
}