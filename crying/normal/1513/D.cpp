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
const int MAXN=2e5+10;
ll T,n,p,ans,a[MAXN],vis[MAXN];
struct Node{
	ll pos,val;
	bool operator<(const Node& n2)const{return val>n2.val;}
};
priority_queue<Node>h;
int main(){
	cin>>T;
	while(T--){
		while(h.size())h.pop();
		cin>>n>>p;
		ans=(n-1)*p;
		rep(i,1,n){
			cin>>a[i];
			vis[i]=0;
			h.push((Node){i,a[i]});
		}
		while(h.size()){
			Node node=h.top();h.pop();
			if(vis[node.pos])continue;
			if(a[node.pos]>=p)break;
			int L=node.pos-1,R=node.pos+1,cnt=1;
			while(L>=1 && vis[L]<2 && a[L]>=a[node.pos] && (a[L]%a[node.pos]==0))L--,cnt++;
			while(R<=n && vis[R]<2 && a[R]>=a[node.pos] && (a[R]%a[node.pos]==0))R++,cnt++;
			ans-=(p-a[node.pos])*(cnt-1);
			rep(j,L+2,R-2)vis[j]+=2;
			vis[L+1]++;if(R-1 != L+1)vis[R-1]++;
		}
		cout<<ans<<endl;
	}
	return 0;
}