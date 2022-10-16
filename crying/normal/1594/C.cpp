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
const int MAXN=3e5+10;
ll T,n;
char c;
char s[MAXN];
void solve(){
	cin>>n>>c>>(s+1);
	int flag=1;rep(i,1,n)if(s[i]!=c)flag=0;
	if(flag==1){
		printf("%d\n",0);return;
	}
	rep(i,2,n){
		int flag=1;
		rep(j,1,n){
			if((ll)i*j>n)break;
			if(s[i*j]!=c)flag=0;
		}
		if(flag==1){
			printf("1\n%d\n",i);
			return;
		}
	}
	printf("2\n%lld %lld\n",n-1,n);
	
} 
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}