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
int T,n,b[MAXN]; 
int lr,rr,r;
int tmp[MAXN],tot,pre[MAXN],bucket[MAXN];
struct BIT{
	int tree[MAXN],n;
	void reset(int n){
		this->n=n;rep(i,1,n)tree[i]=0;
	}
	void add(int k){
		for(int x=k;x<=n;x+=lowbit(x)){
			tree[x]++;
		}
	}
	int query(int k){
		if(!k)return 0; 
		int sum=0;
		for(int x=k;x;x-=lowbit(x)){
			sum+=tree[x];
		}
		return sum;
	}
}tree;
set<int>s;
sit it,k;
int main(){
	cin>>T;
	while(T--){
		cin>>n;tot=0;s.clear();
		tree.reset(n+5);
		int flag=1;
		rep(i,1,n){
			cin>>b[i];
			if(i>1){
				int valid=false;
				k=s.upper_bound(b[i]);
				if(k==it)valid=true;
				if(k!=s.begin()){if(--k == it)valid=true;
					if(*k==b[i] && k!=s.begin())if(--k==it)valid=true;
				}
				if(!valid)flag=0;
			}
			s.insert(b[i]);it=s.find(b[i]);
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	
	}

	return 0;
}
/*
1
6
5 1 2 3 6 7
*/