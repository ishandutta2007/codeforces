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
int n,f[MAXN],a[MAXN],g[MAXN],tot;
char s[MAXN];
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n)a[i]=s[i]-'a'+1;
	f[n]=1;g[1]=a[n];tot=1;f[n]=1;
	per(i,n-1,1){
		if(a[i]>g[tot]){
			g[++tot]=a[i];
			f[i]=tot;
		}else{
			int idx=lower_bound(g+1,g+1+tot,a[i])-g;
			g[idx]=a[i];
			f[i]=idx;
		}
	}
	printf("%d\n",tot);
	rep(i,1,n)printf("%d ",f[i]);
	return 0;
}