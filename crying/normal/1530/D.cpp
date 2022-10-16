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
ll n,a[MAXN],sz[MAXN],ans,t; 
ll nxt[MAXN],tag[MAXN],st[MAXN],tmp[MAXN];
queue<int>q;
vector<int>idx;
void solve(){
	while(q.size())q.pop();
	rep(i,1,n){
		sz[i]=nxt[i]=tag[i]=st[i]=tmp[i]=0;
	}
	ans=0;
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		sz[a[i]]++;
	}
	rep(i,1,n){
		ans+=(sz[i]?1:0);
	}
	printf("%lld\n",ans);
	rep(i,1,n){
		if(!tag[a[i]]){
			nxt[i]=a[i];
			tag[a[i]]=1;
			st[i]=1;
		}
	}
	rep(i,1,n){
		if(nxt[i])continue;
		if(!tag[i]){
			tag[i]=i;
			nxt[i]=i;
		}
	}
	while(q.size())q.pop();
	rep(i,1,n){
		if(!tag[i]){
			q.push(i);
		}
	}
	rep(i,1,n){
		if(!nxt[i]){
			int val1=q.front();
			if(val1!=i){
				nxt[i]=val1;q.pop();
			}else{
				q.pop();
				int val2=q.front();q.pop();
				nxt[i]=val2;q.push(val1);
			}
		}
	}
	idx.clear();
	rep(i,1,n){
		if(st[i])continue;
		idx.pb(i);
	}
	int sz=idx.size();
	rep(j,0,sz-1){
		int ps=(j+1)%sz;
		tmp[idx[j]]=nxt[idx[ps]];
	}
	rep(i,1,n){
		if(tmp[i])nxt[i]=tmp[i];
	}
	rep(i,1,n){
		if(nxt[i]==i){
			rep(j,1,n){
				if(nxt[j]==a[i]){
					//j,i
					nxt[j]=i;
					nxt[i]=a[i]; 
				}
			}
		}
	}
	rep(i,1,n){
		printf("%lld ",nxt[i]);
	} 
	printf("\n");
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}
}