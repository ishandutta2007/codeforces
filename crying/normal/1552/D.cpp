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
const int MAXN=15;
ll T,n,a[MAXN],b[MAXN],tot;
ll flag,target,cs;
void dfs(int r,int sum){
	if(r>n){
		if(sum==target){
			flag=1;
		}
		return;
	}
	dfs(r+1,sum);
	if(r!=cs){
		dfs(r+1,sum+a[r]);
		dfs(r+1,sum-a[r]);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		flag=0;
		rep(i,1,n){
			cin>>a[i];
			b[i]=0;
		}
		if(n==1){
			if(!a[1])printf("YES\n");
			else printf("NO\n");
			continue;
		}
		rep(i,1,n){
			target=a[i];
			cs=i;
			dfs(1,0);
			if(flag)break;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
/*
1
3
1 10 100
*/