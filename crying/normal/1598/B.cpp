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
const int MAXN=1010;
int T,n,a[MAXN][10];
void solve(){
	cin>>n;
	rep(i,1,n){
		rep(j,1,5)cin>>a[i][j];
	}
	rep(x,1,5){
		rep(y,x+1,5){
			ll cnt1=0,cnt2=0,cnt3=0;
			rep(i,1,n){
				if(a[i][x] && !a[i][y])cnt1++;
				if(a[i][y] && !a[i][x])cnt2++; 
				if(a[i][x] && a[i][y])cnt3++;
			}
			if(cnt1+cnt2+cnt3>=n && cnt1+cnt3>=n/2 && cnt2+cnt3>=n/2){
				printf("YES\n");return;
			}
		}
	}
	printf("NO\n");
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}

	return 0;
}