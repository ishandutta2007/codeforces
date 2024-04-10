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
const int MAXN=2010,MAXM=MAXN*MAXN+MAXN;
const ll INF=2e18;
int t,n,k,tot,b;
ll x;
int a[MAXN];
ll suf[MAXN];
char s[MAXN],res[MAXM];
void solve(){
	cin>>n>>k>>x;tot=0;
	cin>>(s+1);
	int cnt=0,m=0;
	rep(j,1,n){
		if(s[j]!='*' && cnt)a[++m]=cnt,cnt=0;
		else if(s[j]=='*')cnt++; 
	}
	if(cnt)a[++m]=cnt;
	suf[m+1]=1;per(i,m,1){
		ll num=1LL*k*a[i]+1;
		if(suf[i+1]>=(INF+num-1)/num)suf[i]=INF;
		else suf[i]=suf[i+1]*num;
	}
	int cur=0;
	rep(j,1,n){
		if(s[j]!='*'){
			res[++tot]='a';continue;
		}else if(s[j]!=s[j-1]){
			cur++;
			ll num=1LL*suf[cur+1];
			rep(k,1,(x-1)/num)res[++tot]='b';
			
			x-=(x-1)/num*num;
		}
	}
	rep(j,1,tot)putchar(res[j]);putchar('\n');
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}


	return 0;
}