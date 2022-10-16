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
const int MAXN=1e5+10;
int T,n;
int sum[5],per[5],use[5];
ll ans;
char s[MAXN],t[MAXN],res[MAXN];
int bucket[26],nxt[MAXN],p[MAXN],start[26];
struct BIT{
	int n,tree[MAXN];
	void reset(int n){
		this->n=n;
		rep(i,1,n)tree[i]=0;	
	}
	void add(int k){
		for(int x=k;x<=n;x+=lowbit(x)){
			tree[x]++;
		}
	}
	int query(int k){
		int sum=0;
		for(int x=k;x;x-=lowbit(x)){
			sum+=tree[x];
		}
		return sum;
	}
}tree;
ll calc(){
	//t->s
	memset(bucket,0,sizeof bucket);
	per(i,n,1){
		nxt[i]=bucket[s[i]-'A'];
		bucket[s[i]-'A']=i;
	}
	rep(i,0,25)start[i]=bucket[i];
	rep(i,1,n){
		p[i]=start[t[i]-'A'];
		start[t[i]-'A']=nxt[start[t[i]-'A']];
	}
	//p
	tree.reset(n+10);
	ll sum=0;
	per(i,n,1){
		sum+=tree.query(p[i]);
		tree.add(p[i]);
	}
	return sum;
}
void dfs(int r){
	if(r==5){
		// 
		int cnt=1;
		rep(i,1,4){
			char ch;
			if(per[i]==1)ch='A';
			else if(per[i]==2)ch='N';
			else if(per[i]==3)ch='O';
			else ch='T';
			rep(j,1,sum[per[i]])t[cnt++]=ch;
		}
		ll ret=calc();
		if(ret>ans){
			ans=ret;
			rep(i,1,n)res[i]=t[i];
		}
		return;
	}
	rep(i,1,4){
		if(use[i])continue;
		per[r]=i;use[i]=1;
		dfs(r+1);
		use[i]=0;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		rep(i,1,n+1)t[i]=0,res[i]=0;
		sum[1]=sum[2]=sum[3]=sum[4]=0;
		use[1]=use[2]=use[3]=use[4]=0;
		rep(i,1,n){
			if(s[i]=='A')sum[1]++;
			else if(s[i]=='N')sum[2]++;
			else if(s[i]=='O')sum[3]++;
			else sum[4]++;
		}
		ans=-1;
		dfs(1);
		printf("%s\n",res+1);
	}

	return 0;
}