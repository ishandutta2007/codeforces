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
int T,n,a[MAXN],cnt1[MAXN][2],cnt2[MAXN][2]; 
int main(){
	cin>>T;
	while(T--){
		memset(cnt1,0,sizeof cnt1);
		memset(cnt2,0,sizeof cnt2);
		cin>>n;
		rep(i,1,n){
			cin>>a[i];
			cnt1[a[i]][odd(i)]++;
		}
		sort(a+1,a+1+n);
		rep(i,1,n){
			cnt2[a[i]][odd(i)]++;
		}
		int flag=1;
		rep(i,1,n){
			if(cnt1[a[i]][0]!=cnt2[a[i]][0]){
				flag=0;break;
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}